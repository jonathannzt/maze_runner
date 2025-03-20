#include <iostream>
#include "Maze.h"
#include "MazeGenerator.h"
#include "MazeSolver.h"

int main() {
    int width = 20;
    int height = 10;

    Maze maze(width, height);
    MazeGenerator generator;
    generator.generateMaze(maze, 0, 0);

    MazeSolver solver;
    bool found = solver.solveAStar(maze, 0, 0, width - 1, height - 1);
    maze.display(0, 0, width - 1, height - 1);

    if (found) {
        std::cout << "Chemin trouve ! (chemin indique par '*')" << std::endl;
    } else {
        std::cout << "Aucun chemin trouve." << std::endl;
    }

    return 0;
}
