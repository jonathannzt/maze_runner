#include "Maze.h"
#include <iostream>

Maze::Maze(int width, int height)
    : m_width(width), m_height(height), m_cells(width * height)
{
}

Cell& Maze::getCell(int x, int y) {
    return m_cells[y * m_width + x];
}

const Cell& Maze::getCell(int x, int y) const {
    return m_cells[y * m_width + x];
}

void Maze::display(int startX, int startY, int goalX, int goalY) const {
    for (int y = 0; y < m_height; ++y) {
        for (int x = 0; x < m_width; ++x) {
            std::cout << "+";
            if (getCell(x, y).topWall) {
                std::cout << "--";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << "+" << std::endl;

        for (int x = 0; x < m_width; ++x) {
            if (getCell(x, y).leftWall) {
                std::cout << "|";
            } else {
                std::cout << " ";
            }

            if (x == startX && y == startY) {
                std::cout << "E ";
            }
            else if (x == goalX && y == goalY) {
                std::cout << "X ";
            }
            else if (getCell(x, y).inPath) {
                std::cout << "* ";
            }
            else {
                std::cout << "  ";
            }
        }

        if (getCell(m_width - 1, y).rightWall) {
            std::cout << "|";
        } else {
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    for (int x = 0; x < m_width; ++x) {
        std::cout << "+";
        if (getCell(x, m_height - 1).bottomWall) {
            std::cout << "--";
        } else {
            std::cout << "  ";
        }
    }
    std::cout << "+" << std::endl;
}
