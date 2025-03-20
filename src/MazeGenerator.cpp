#include "MazeGenerator.h"
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>

struct Direction {
    int dx;
    int dy;
};

static std::vector<Direction> directions = {
    { 0, -1 }, // Haut
    { 0,  1 }, // Bas
    {-1,  0 }, // Gauche
    { 1,  0 }  // Droite
};

static std::mt19937 rng(static_cast<unsigned long>(std::time(nullptr)));

void MazeGenerator::generateMaze(Maze& maze, int startX, int startY) {
    int width = maze.getWidth();
    int height = maze.getHeight();

    maze.getCell(startX, startY).visited = true;
    std::shuffle(directions.begin(), directions.end(), rng);

    for (auto& dir : directions) {
        int nx = startX + dir.dx;
        int ny = startY + dir.dy;

        if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
            if (!maze.getCell(nx, ny).visited) {
                if (dir.dx == 0 && dir.dy == -1) {
                    // Haut
                    maze.getCell(startX, startY).topWall = false;
                    maze.getCell(nx, ny).bottomWall = false;
                } else if (dir.dx == 0 && dir.dy == 1) {
                    // Bas
                    maze.getCell(startX, startY).bottomWall = false;
                    maze.getCell(nx, ny).topWall = false;
                } else if (dir.dx == -1 && dir.dy == 0) {
                    // Gauche
                    maze.getCell(startX, startY).leftWall = false;
                    maze.getCell(nx, ny).rightWall = false;
                } else if (dir.dx == 1 && dir.dy == 0) {
                    // Droite
                    maze.getCell(startX, startY).rightWall = false;
                    maze.getCell(nx, ny).leftWall = false;
                }

                maze.getCell(nx, ny).visited = true;
                generateMaze(maze, nx, ny);
            }
        }
    }
}
