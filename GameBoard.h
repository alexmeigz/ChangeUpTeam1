#pragma once

#include <vector>
#include "GoalPost.h"

template <class T>
using Vector2D = std::vector<std::vector<T>>;

class GameBoard {
public:
    GameBoard(int size);
    int removeBall(int x, int y);
    bool addBall(int player, int x, int y);

    Vector2D<int> getLayerX(int x) const;
    Vector2D<int> getLayerY(int y) const;
    Vector2D<int> getLayerZ(int z) const;
private:
    std::vector<int> fillPost(const std::vector<int> &post) const;
    
    Vector2D<GoalPost> board;
    const int SIZE;
};
