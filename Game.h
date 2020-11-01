#pragma once

#include <string>
#include "Player.h"
#include "GameBoard.h"

enum class Move {ADD, REMOVE};

class Game {
public:
    Game(int size, int maxBall);
    void printBoardState(std::string state) const;
    bool makeMove(Move move, int x, int y);
    bool finished() const; // NEED TO CHECK WIN CONDITION - use gameboard layer method
    int whoseTurn() const; // return whose turn
    int movesRemaining() const; // of current player
    int getScore(int player) const;
    int ballsLeft() const; // of current player
    ~Game();
private:
    // todo: remove dynamic alloc:
    GameBoard * gameboard;
    Player * player1;
    Player * player2;

    bool turnTracker; // WE HAVE TO SWITCH TURNS SOMEWHERE
    int turn; // on turn 1, there can only be 2 moves
    int numMoves; // 3 moves per turn before switch
};