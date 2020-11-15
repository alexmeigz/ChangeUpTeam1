#include "Game.h"

Game::Game(int size, int numPlayers, int maxBall, int winningScore, int movesPerTurn, int movesFirstTurn, int removesPerTurn)
  : WINNING_SCORE(winningScore),
    MOVES_PER_TURN(movesPerTurn),
    MOVES_FIRST_TURN(movesFirstTurn),
    REMOVES_PER_TURN(removesPerTurn),
    NUM_PLAYERS(numPlayers),
    gameboard(size),
    SIZE(size)
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
    player_arr[0].setScore(0);
    player_arr[1].setScore(0);

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

// checks if all the values in a vector are the same:
bool isSame(std::vector<int> v) {
    int ref = v[0];
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] != ref) {
            return false;
        }
    }
    return true;
}

// checks if all of the columns in a 2d vector have same value and adds corresponding score
void countVertical(Vector2D<int> layer, int &x, int &y) {
    // go through each columns:
    for (int i = 0; i < layer.size(); ++i) {
        // first value in column:
        int player = layer[i][0];

        // if player had ball and the column is the same, increment values
        if (player && isSame(layer[i])) {
            player == 1 ? ++x : ++y;
        }
    }
}

// checks if all of the rows in a 2d vector have same value and adds corresponding score
void countHorizontal(Vector2D<int> layer, int &x, int &y) {
    for (int i = 0; i < layer.size(); ++i) {
        // first value in row
        int player = layer[0][i];

        // build up row
        std::vector<int> row(layer[i].size());
        for (int j = 0; j < row.size(); ++i) {
            row[j] = layer[j][i];
        }

        // check with row
        if (player && isSame(row)) {
            player == 1 ? ++x : ++y;
        }
    }
}

void Game::setZScore() {
    int x = 0, y = 0;
    for (int i = 0; i < SIZE; ++i) {
        // use the x layers to get the columns
        Vector2D<int> layer = gameboard.getLayerX(i);
        countVertical(layer, x, y);
    }
    player_arr[0].addScore(x);
    player_arr[1].addScore(y);
}

void Game::setXScore() {
    int x = 0, y = 0;
    for (int i = 0; i < SIZE; ++i) {
        // columns of z layer are the x rows
        Vector2D<int> layer = gameboard.getLayerZ(i);
        countVertical(layer, x, y);
    }
    player_arr[0].addScore(x);
    player_arr[1].addScore(y);
}

void Game::setYScore() {
    int x = 0, y = 0;
    for (int i = 0; i < SIZE; ++i) {
        // rows of z layer are the y rows:
        Vector2D<int> layer = gameboard.getLayerZ(i);
        countHorizontal(layer, x, y);
    }
    player_arr[0].addScore(x);
    player_arr[1].addScore(y);
}

int Game::ballsLeft() const {
    Player p = this->player_arr[this->whoseTurn() - 1];
    return p.ballsLeft();
}

void Game::displayBoard() const {
	gameboard.displayBoard();
}
