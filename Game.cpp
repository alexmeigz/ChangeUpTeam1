#include "Game.h"
#include <string>

Game::Game(int size, int numPlayers, int maxBall, int winningScore, int movesPerTurn, int movesFirstTurn, int removesPerTurn)
  : WINNING_SCORE(winningScore),
    MOVES_PER_TURN(movesPerTurn),
    MOVES_FIRST_TURN(movesFirstTurn),
    REMOVES_PER_TURN(removesPerTurn),
    NUM_PLAYERS(numPlayers),
    gameboard(size),
    player_arr(numPlayers)
{    

    for (int i = 1; i <= numPlayers; ++i) {
        this->player_arr[i] = Player(i, maxBall);
    }   
 }

int Game::maxMoves() const {
    return turn == 1 ? MOVES_FIRST_TURN : MOVES_PER_TURN;
}

void Game::setScores() {

}

bool Game::finished() const {
    for (int i = 0; i < this->NUM_PLAYERS; ++i) {
        if (this->player_arr[i].getScore() == this->WINNING_SCORE) {
            return true;
        }
    }
    return false;
}

bool Game::makeMove(std::string move, int x, int y) {
    Player currentPlayer = this->player_arr[this->whoseTurn() - 1];

    // if they aren't allowed to remove or add:
    if (move == "remove" && this->removes == this->REMOVES_PER_TURN) {
        return false;
    }
    else if (move == "add" && currentPlayer.ballsLeft() == 0) {
        return false;
    }

    // try to make the move:
    int result = this->tryMove(move, x, y);

    // move was unsuccessful
    if (!result) {
        return false;
    }

    if (move == "remove") {
        ++this->removes;
        this->player_arr[result - 1].playerRemoveBall();
    }
    else if (move == "add") {
        this->player_arr[this->whoseTurn() - 1].playerAddBall();
    }

    ++this->moves;

    // switch player's turn:
    if (this->moves == this->maxMoves()) {
        this->moves = 0;
        this->removes = 0;

        this->turnTracker = !this->turnTracker;
        ++this->turn;
    }

    this->setScores();
}

int Game::tryMove(std::string move, int x, int y) {
    if (move == "add") {
        return this->gameboard.addBall(this->whoseTurn(), x, y);
    }
    else if (move == "remove") {
        return this->gameboard.removeBall(x, y);
    }

    return false;
}