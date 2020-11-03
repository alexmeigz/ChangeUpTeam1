#include "Game.h"
#include <iostream>

Game::Game(int size, int maxBall, int winningScore, int movesPerTurn, int movesFirstTurn, int removesPerTurn) 
: WINNING_SCORE(winningScore), MOVES_PER_TURN(movesPerTurn), MOVES_FIRST_TURN(movesFirstTurn), REMOVES_PER_TURN(removesPerTurn) {
    
    this->player1 = new Player(1,  maxBall);
    this->player2 = new Player(2, maxBall);

    this->gameboard = new GameBoard(size);

    this->turnTracker = true;
    this->turn = 0;
    this->moves = 0;
}

void Game::printBoardState(std::string state) const {
    /*
    IMPLEMENT

    when getting a layer, make sure to delete the array after => utilities.cpp
    */
}

bool Game::makeMove(Move move, int x, int y) {
    bool result = this->tryMove(move, x, y);

    /*
    
    KEEP TRACK OF TURNS, MOVES, REMOVES only if tryMove was successful

    switch player for next round if movesRemaining() == 0
    
    */
}

bool Game::tryMove(Move move, int x, int y) {
    /*
    
    Veryify 0<=x<SIZE, 0<=y<SIZE
    
    */
    switch (move) {
        case Move::ADD: {
            Player * player = this->currentPlayer();

            if (!player->ballsLeft()) {
                return false;
            }
            bool addedBall = this->gameboard->addBall(player->playerGetId(), x, y);

            if (addedBall) {
                player->playerAddBall();
            }

            return addedBall;
        }

        case Move::REMOVE: {
            if (!this->canRemove()) {
                return false;
            }

            int playerId = this->gameboard->removeBall(x, y);
            
            switch (playerId) {
                case 1: 
                    this->player1->playerRemoveBall();
                    return true;
                case 2:
                    this->player2->playerRemoveBall();
                    return true;
            }
        }
    }
    return false;
}

Player * Game::currentPlayer() const {
    return turnTracker ? this->player1 : this->player2;
}

bool Game::finished() const {
    /*
    IMPLEMENT

    check players' score
    */
}

int Game::whoseTurn() const {
    /*
    IMPLEMENT
    */
}

int Game::movesRemaining() const {
    return this->turnMoves() - this->moves;
}

int Game::getScore(int player) const {
    /*
    IMPLEMENT
    */
}

int Game::ballsLeft() const {
    /*
    IMPLEMENT
    */
}

bool Game::canRemove() const {
    /*
    IMPLEMENT
    */
}

void Game::setScores() {
    /*
    IMPLEMENT

    Count 3 in a rows from the getLayer functions (remember to delete array after)

    I think we also have to account for the 4 remaining diagonals

    */
}

int Game::turnMoves() const {
    return this->turn == 0 ? this->MOVES_FIRST_TURN : this->MOVES_PER_TURN;
}

Game::~Game() {
    delete this->player1;
    delete this->player2;
    delete this->gameboard;
}
