#pragma once

#include <vector>
#include <iostream>
#include "Player.h"
#include "GoalPost.h"

/*
enum class X : int {LEFT = 0, MIDDLE = 1, RIGHT = 2};
enum class Y : int {BACK = 0, MEDIUM = 1, FRONT = 2};
enum class Z : int {BOTTOM = 0, CENTER = 1, TOP = 2};
*/

class GameBoard {
public:
    GameBoard(int size);
    int removeBall(int x, int y);
    bool addBall(int player, int x, int y);
    int ** getLayerX(int x) const;
    int ** getLayerY(int y) const;
    int ** getLayerZ(int z) const;
    ~GameBoard();
private:
    const int SIZE;
    GoalPost *** board;
};