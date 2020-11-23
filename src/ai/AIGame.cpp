#include <iostream>
#include <regex>
#include <vector>
#include <utility>
#include "../../include/ai/AIGame.h"

AIGame::AIGame(int playerId) : PLAYER_ID(playerId) {
	if (playerId == 2) {
		makeMove("", -1, -1);
	}
}

bool AIGame::makeMove(std::string move, int x, int y) {
	bool playerMove = Game::makeMove(move, x, y);

	while (Game::whoseTurn() != PLAYER_ID) {
		this->AIMakeMove();    
	}

	return playerMove;
}

void AIGame::AIMakeMove(){
	vector<pair<int, int> > availableAdds = Game::availableAdds(),
		availableRemoves = Game::availableRemoves();
	int addSize = availableAdds.size();

	// available adds now contains all possible move pairs
	availableAdds.insert(std::end(availableAdds), std::begin(availableRemoves), std::end(availableRemoves));

	int num = rand() % availableAdds.size();

	std::string computerMove = num < addSize ? "ADD" : "REMOVE";
	int x = availableAdds[num].first,
	    y = availableAdds[num].second;

	Game::makeMove(computerMove, x, y);
}