#pragma once

#include <string>
#include "Player.h"
#include "GameBoard.h"

enum class Move {ADD, REMOVE};

class Game {
public:
    Game(int size, int maxBall);
    void printBoardState(std::string state) const;
    bool makeMove(Move move, X x, Y y);
    bool finished(); // NEED TO CHECK WIN CONDITION - use gameboard layer method
    ~Game();
private:
    GameBoard * gameboard;
    Player * player1;
    Player * player2;
    bool turnTracker; // WE HAVE TO SWITCH TURNS SOMEWHERE
};