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
    IMPLEMENT

    when getting a layer, make sure to delete the array after => utilities.cpp
    */
}

bool Game::makeMove(Move move, int x, int y) {
    Player * player = turnTracker ? this->player1 : this->player2;

    /*
    
    KEEP TRACK OF TURNS
    
    */
            
    switch (move) {
        case Move::ADD: {
            if (!player->ballsLeft()) {
                return false;
            }
            bool addedBall = this->gameboard->addBall(player->playerGetId(), x, y);

            /*
            
            Check for three in a row on the same x, y, z, and possibly diagonals???
                - add / remove score of players

            */

            if (addedBall) {
                player->playerAddBall();
            }
            return addedBall;
        }

        case Move::REMOVE: {
            int playerId = this->gameboard->removeBall(x, y);
            /*
            
            Check for three in a rows, might have to check all because removing changes everything
                - add / remove score of players

            */
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

bool Game::finished() const {
    /*
    IMPLEMENT
    */
}

int Game::whoseTurn() const {
    /*
    IMPLEMENT
    */
}

int Game::movesRemaining() const {
    /*
    IMPLEMENT
    */
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

Game::~Game() {
    delete this->player1;
    delete this->player2;
    delete this->gameboard;
}
