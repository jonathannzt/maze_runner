#include "MazeSolver.h"
#include <queue>
#include <cmath>
#include <limits>
#include <algorithm>

struct Node {
    int x;
    int y;
    float fCost; 
    float gCost; 
    float hCost; 
};

struct CompareNode {
    bool operator()(const Node& a, const Node& b) {
        return a.fCost > b.fCost;
    }
};

static float heuristic(int x1, int y1, int x2, int y2) {
    return static_cast<float>(std::abs(x1 - x2) + std::abs(y1 - y2));
}

bool MazeSolver::solveAStar(Maze& maze, int startX, int startY, int goalX, int goalY) {
    int width = maze.getWidth();
    int height = maze.getHeight();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            maze.getCell(x, y).inPath = false;
        }
    }

    std::vector<float> gCostGrid(width * height, std::numeric_limits<float>::infinity());
    std::vector<int> parentGrid(width * height, -1); 

    auto index = [&](int x, int y) {
        return y * width + x;
    };

    Node startNode{startX, startY, 0.0f, 0.0f, heuristic(startX, startY, goalX, goalY)};
    gCostGrid[index(startX, startY)] = 0.0f;

    std::priority_queue<Node, std::vector<Node>, CompareNode> openSet;
    openSet.push(startNode);

    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();

        if (current.x == goalX && current.y == goalY) {
            int currIndex = index(goalX, goalY);
            while (currIndex != -1) {
                int cx = currIndex % width;
                int cy = currIndex / width;
                maze.getCell(cx, cy).inPath = true;
                currIndex = parentGrid[currIndex];
            }
            return true;
        }

        if (gCostGrid[index(current.x, current.y)] < current.gCost) {
            continue;
        }

        struct Neighbor { int x; int y; };
        std::vector<Neighbor> neighbors;

        // Haut
        if (!maze.getCell(current.x, current.y).topWall && current.y > 0) {
            neighbors.push_back({current.x, current.y - 1});
        }
        // Bas
        if (!maze.getCell(current.x, current.y).bottomWall && current.y < height - 1) {
            neighbors.push_back({current.x, current.y + 1});
        }
        // Gauche
        if (!maze.getCell(current.x, current.y).leftWall && current.x > 0) {
            neighbors.push_back({current.x - 1, current.y});
        }
        // Droite
        if (!maze.getCell(current.x, current.y).rightWall && current.x < width - 1) {
            neighbors.push_back({current.x + 1, current.y});
        }

        for (auto& nb : neighbors) {
            float tentativeG = current.gCost + 1.0f;

            if (tentativeG < gCostGrid[index(nb.x, nb.y)]) {
                parentGrid[index(nb.x, nb.y)] = index(current.x, current.y);
                gCostGrid[index(nb.x, nb.y)] = tentativeG;
                float h = heuristic(nb.x, nb.y, goalX, goalY);
                float f = tentativeG + h;

                Node neighborNode{ nb.x, nb.y, f, tentativeG, h };
                openSet.push(neighborNode);
            }
        }
    }

    return false; // pas de chemin trouvé
}
