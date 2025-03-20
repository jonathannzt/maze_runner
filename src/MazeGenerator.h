#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H

#include "Maze.h"

// Générateur de labyrinthe
class MazeGenerator {
    public:
        MazeGenerator() = default;
        void generateMaze(Maze& maze, int startX = 0, int startY = 0);
};

#endif
