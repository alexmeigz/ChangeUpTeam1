#include "Game.h"

Game::Game(int size, int numPlayers, int maxBall, int winningScore, int movesPerTurn, int movesFirstTurn, int removesPerTurn)
  : WINNING_SCORE(winningScore),
    MOVES_PER_TURN(movesPerTurn),
    MOVES_FIRST_TURN(movesFirstTurn),
    REMOVES_PER_TURN(removesPerTurn),
    NUM_PLAYERS(numPlayers),
    gameboard(size)
{    
    turnTracker = true;
    moves = 0;
    removes = 0;
    turn = 1;

    Player player1(1, maxBall);
    Player player2(2, maxBall);

    this->player_arr = std::vector<Player>{player1, player2}; 
}

int Game::whoseTurn() const {
    return turnTracker ? 1 : 2;
}

bool Game::canRemove() const {
    return removes < REMOVES_PER_TURN;
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

    return true;
}

int Game::maxMoves() const {
    return turn == 1 ? MOVES_FIRST_TURN : MOVES_PER_TURN;
}

int Game::tryMove(std::string move, int x, int y) {
    if (move == "add" && ballsLeft()) {
        return this->gameboard.addBall(this->whoseTurn(), x, y);
    }
    else if (move == "remove" && canRemove()) {
        return this->gameboard.removeBall(x, y);
    }

    return false;
}

int Game::movesRemaining() const {
    return this->maxMoves() - this->moves;
}

int Game::getScore(int player) const {
    if (player > 0 && player <= this->NUM_PLAYERS) {
        return this->player_arr[player - 1].getScore(); 
    }
    return -1;
}

void Game::setScores() {
    set3dDiagScore();
    set2dDiagScore();
    setZScore();
    setXScore();
    setYScore();
}

void Game::set3dDiagScore() {

}

void Game::set2dDiagScore() {

}

void Game::setZScore() {

}

void Game::setXScore() {

}

void Game::setYScore() {
    
}

int Game::ballsLeft() const {
    Player p = this->player_arr[this->whoseTurn() - 1];
    return p.ballsLeft();
}

void Game::displayBoard() const {
	gameboard.displayBoard();
}
