#pragma once

#include <vector>
#include <iostream>
#include "Player.h"
#include "GoalPost.h"

enum class X : int {LEFT = 0, MIDDLE = 1, RIGHT = 2};
enum class Y : int {BACK = 0, MEDIUM = 1, FRONT = 2};
enum class Z : int {BOTTOM = 0, CENTER = 1, TOP = 2};

class GameBoard {
public:
    GameBoard(int size);
    int removeBall(X x, Y y);
    bool addBall(int player, X x, Y y);
    int ** getLayer(X x) const;
    int ** getLayer(Y y) const;
    int ** getLayer(Z z) const;
    ~GameBoard();
private:
    const int SIZE;
    GoalPost *** board;
};