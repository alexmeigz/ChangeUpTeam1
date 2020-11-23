#include <iostream>
#include <regex>
#include <vector>
#include <utility>
#include "AIGame.h"

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

	// available adds now contains all possible move pairs
	availableAdds.insert(std::end(availableAdds), std::begin(availableRemoves), std::end(availableRemoves));

	int num = rand() % availableAdds.size();

	std::string computerMove = num < availableAdds.size() ? "ADD" : "REMOVE";
	int x = availableAdds[num].first,
	    y = availableRemoves[num].second;

	Game::makeMove(computerMove, x, y);
	//std::cout << "Computer move: " << computerMove << " " << x << " " << y << std::endl;
}

void AIGame::playCPU(){
	std::regex input_rgx("(add|remove) (\\d)");

	std::cout << "---------------------------------------------------------------------------\n"; 
	while (!finished()) {
		displayBoard();
		std::cout << "---------------------------------------------------------------------------\n"; 
		std::cout << "Current Score" << endl;
		std::cout << "Player 1: O : " << getScore(1) << "\nPlayer 2: X : " << getScore(2) << "\n\n";
		std::cout << "It is player " << whoseTurn() << "'s turn.\n";
		std::cout << "  - " << movesRemaining() << " moves remaining.\n";
		std::cout << "  - " << canRemove() << " removes remaining.\n";
		std::cout << "  - " << ballsLeft() << " balls left\n";

		std::string move = "";
		int slot_num;
		int x = -1;
		int y = -1;

		std::cout << "---------------------------------------------------------------------------\n\n"; 
		do {
			string slots =
				"    1 -- 2 -- 3\n"
				"   /    /    /     << Slot Numbers\n"
				"  4 -- 5 -- 6\n"
				" /    /    /        Move Format: add/remove slot#\n"
				"7 -- 8 -- 9         Make a Move: ";
			std::cout << slots;
			std::string input;
			std::getline(std::cin, input);
			std::smatch matches;

			if (std::regex_search(input, matches, input_rgx)) {
				move = matches.str(1);
				for(int i = 0; i < move.size(); i++)
					move[i] = static_cast<char>(toupper(move[i]));
				slot_num = stoi(matches.str(2)) - 1;
				x = slot_num % 3;
				y = slot_num / 3;	
			}

		} while(!makeMove(move, x, y));

		std::cout << "---------------------------------------------------------------------------\n\n"; 
	}

	displayBoard();

	if(getScore(1) > getScore(2)){
		cout << "PLAYER 1 WINS!" << endl;
	} else {
		cout << "PLAYER 2 WINS!" << endl;
	}	
}
