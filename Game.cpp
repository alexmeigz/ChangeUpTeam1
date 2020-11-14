#include "Game.h"
#include <string>

Game::Game(int size, int maxBall, int winningScore, int movesPerTurn, int movesFirstTurn, int removesPerTurn)
 : WINNING_SCORE(winningScore), MOVES_PER_TURN(movesPerTurn), MOVES_FIRST_TURN(movesFirstTurn), REMOVES_PER_TURN(removesPerTUrn) {
    this->gameboard = GameBoard(size);
    
 }

int Game::maxMoves() const {
    return turn == 1 ? MOVES_FIRST_TURN : MOVES_PER_TURN;
}

void Game::setScores() {

}

bool tryMove(std::string move, int x, int y) {
    if (move == "add") {
        return this->gameboard.addBall(this->whoseTurn(), x, y);
    }
    else if (move == "remove") {
        return this->gameboard.removeBall(x, y);
    }

    return false;
}