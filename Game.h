#pragma once

#include <string>
#include "Player.h"
#include "GameBoard.h"

enum class Move {ADD, REMOVE};

class Game {
public:
    Game(int size, int maxBall, int winningScore, int movesPerTurn, int movesFirstTurn, int removesPerTurn);
    
    void printBoardState(std::string state) const;
    bool makeMove(Move move, int x, int y); 
    bool finished() const; 

    int whoseTurn() const; // return whose turn
    bool canRemove() const;
    int movesRemaining() const; // of current player
    int getScore(int player) const;
    int ballsLeft() const; // of current player

    ~Game();
private:
    GameBoard * gameboard;
    Player * player1;
    Player * player2;

    int turnMoves() const;
    Player * currentPlayer() const;

    void setScores();
    bool tryMove(Move move, int x, int y); // returns false if specified move cannot be made

    bool turnTracker; // true if player1's turn
    int turn; // on turn 1, there can only be 2 moves
    int moves; // 3 moves per turn before switch
    int removes; // only 1 remove per turn

    const int WINNING_SCORE;
    const int MOVES_PER_TURN;
    const int MOVES_FIRST_TURN;
    const int REMOVES_PER_TURN;
};