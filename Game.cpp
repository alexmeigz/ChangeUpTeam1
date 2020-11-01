#include "Game.h"
#include <iostream>

Game::Game(int size) : SIZE(size) {
    this->player1 = new Player(1);
    this->player1 = new Player(2);

    turnTracker = true;
    this->gameboard = new GameBoard(size, this->player1, this->player2);
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
            std::cout << "ADDING" << std::endl;

            bool addedBall = this->gameboard->addBall(player->playerGetId(), x, y);

            std::cout << addedBall << std::endl;

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
