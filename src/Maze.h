#ifndef MAZE_H
#define MAZE_H

#include <vector>

// Cellule d'un labyrinthe
struct Cell {
    bool visited;
    bool inPath;
    bool topWall;
    bool bottomWall;
    bool leftWall;
    bool rightWall;

    Cell()
        : visited(false), inPath(false),
          topWall(true), bottomWall(true),
          leftWall(true), rightWall(true) {}
};

class Maze {
public:
    Maze(int width, int height);

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }

    Cell& getCell(int x, int y);
    const Cell& getCell(int x, int y) const;

    void display(int startX, int startY, int goalX, int goalY) const;

private:
    int m_width;
    int m_height;
    std::vector<Cell> m_cells;
};

#endif
