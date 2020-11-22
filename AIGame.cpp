#include "AIGame.h"
#include <iostream>
#include <vector>
#include <utility>

bool AIGame::makeMove(std::string move, int x, int y) {
    bool playerMove = Game::makeMove(move, x, y);

    while (Game::whoseTurn() != PLAYER_ID) {
        this->AIMakeMove();    
    }

    return playerMove;
}


void AIGame::AIMakeMove(){
    vector<pair<int, int>> availableAdds = Game::avaiableAdds(),
                            availableRemoves = Game::avaiableRemoves();

    // available adds now contains all possible move pairs
    availableAdds.insert(std::end(availableAdds), std::begin(availableRemoves), std::end(availableRemoves));
    
    int num = rand() % availableAdds.size();
    
    std::string computerMove = num < availableAdds.size() ? "ADD" : "REMOVE";
    int x = availableAdds[num].first,
        y = availableRemoves[num].second;

    Game::makeMove(computerMove, x, y);
    //std::cout << "Computer move: " << computerMove << " " << x << " " << y << std::endl;
}