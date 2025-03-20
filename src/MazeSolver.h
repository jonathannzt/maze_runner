#ifndef MAZESOLVER_H
#define MAZESOLVER_H

#include "Maze.h"
#include <vector>

// Solveur de labyrinthe
class MazeSolver {
    public:
        MazeSolver() = default;
        bool solveAStar(Maze& maze, int startX, int startY, int goalX, int goalY);
};

#endif
