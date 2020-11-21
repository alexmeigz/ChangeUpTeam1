#include "AIGame.h"
#include <iostream>

bool AIGame::makeMove(std::string move, int x, int y) {
    bool playerMove = Game::makeMove(move, x, y);

    while (Game::whoseTurn() != PLAYER_ID) {
        this->AIMakeMove();    
    }

    return playerMove;
}


void AIGame::AIMakeMove(){
    std::string computerMove;
    int x, y;
    do {
        computerMove = rand() % 2 > 0.5 ? "ADD" : "REMOVE";
        x = rand() % 3 + 1;
        y = rand() % 3 + 1;
    } while(!Game::makeMove(computerMove, x, y));

    std::cout << "Computer move: " << computerMove << " " << x << " " << y << std::endl;
}