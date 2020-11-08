#pragma once

#include <vector>
#include "utilities.h"

class GameBoard {
public:
    GameBoard(int size);
    bool removeBall(int x, int y);
    bool addBall(int player, int x, int y);

    Vector2D<int> getLayerX(int x) const;
    Vector2D<int> getLayerY(int y) const;
    Vector2D<int> getLayerZ(int z) const;
public:
    std::vector<int> fillPost(std::vector<int> post) const;
    Vector2D<GoalPost> board;
    const int SIZE;
};