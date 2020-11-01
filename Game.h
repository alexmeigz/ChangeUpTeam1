#pragma once

#include <string>
#include "Player.h"
#include "GameBoard.h"

enum class Move {ADD, REMOVE};

class Game {
public:
    Game(int size);
    void printBoardState(std::string state) const;
    bool makeMove(Move move, X x, Y y);
    ~Game();
private:
    const int SIZE;
    GameBoard * gameboard;
    Player * player1;
    Player * player2;
    bool turnTracker;
};