#include "Game.h"
#include <iostream>

Game::Game(int size, int maxBall) {
    this->player1 = new Player(1,  maxBall);
    this->player2 = new Player(2, maxBall);

    turnTracker = true;
    this->gameboard = new GameBoard(size);
}

void Game::printBoardState(std::string state) const {
    /*
    IMLEMENT
    */
}

bool Game::makeMove(Move move, X x, Y y) {
    Player * player = turnTracker ? this->player1 : this->player2;

    switch (move) {
        case Move::ADD: {
            if (!player->hasBallsLeft()) {
                return false;
            }
            bool addedBall = this->gameboard->addBall(player->playerGetId(), x, y);
            if (addedBall) {
                player->playerAddBall();
            }
            return addedBall;
        }

        case Move::REMOVE: {
            int playerId = this->gameboard->removeBall(x, y);
            switch (playerId) {
                case 1: 
                    player1->playerRemoveBall();
                    return true;
                case 2:
                    player2->playerRemoveBall();
                    return true;
            }
        }
    }
    return false;
}

Game::~Game() {
    delete this->player1;
    delete this->player2;
    delete this->gameboard;
}
