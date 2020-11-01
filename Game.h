#pragma once

#include <string>
#include "Player.h"
#include "GameBoard.h"

enum class Move {ADD, REMOVE};

class Game {
public:
    Game(int size, int maxBall, int winningScore, int movesPerTurn, int movesFirstTurn);
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

    void setScores();
    int turnMoves() const;

    bool turnTracker; // true if player1's turn
    int turn; // on turn 1, there can only be 2 moves
    int moves; // 3 moves per turn before switch

    const int WINNING_SCORE;
    const int MOVES_PER_TURN;
    const int MOVES_FIRST_TURN;
};