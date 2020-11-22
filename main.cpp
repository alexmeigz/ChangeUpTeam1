#include <iostream>
#include <vector>
#include <string>
#include "AIGame.h"
#include <regex>
#include <cctype>
#include <cstdlib>

const int SIZE = 3;
const int NUM_PLAYERS = 2;
const int MAX_BALL = 16;
const int WINNING_SCORE = 4;
const int MOVES_PER_TURN = 3;
const int MOVES_FIRST_TURN = 2;
const int REMOVES_PER_TURN = 1;

int main() {
	AIGame game(1,
			SIZE, 
			NUM_PLAYERS, 
			MAX_BALL, 
			WINNING_SCORE, 
			MOVES_PER_TURN, 
			MOVES_FIRST_TURN, 
			REMOVES_PER_TURN);

	std::regex input_rgx("(add|remove) (\\d)");

	std::cout << "---------------------------------------------------------------------------\n"; 
	while (!game.finished()) {
		game.displayBoard();
		std::cout << "---------------------------------------------------------------------------\n"; 
		std::cout << "Current Score" << endl;
		std::cout << "Player 1: O : " << game.getScore(1) << "\nPlayer 2: X : " << game.getScore(2) << "\n\n";
		std::cout << "It is player " << game.whoseTurn() << "'s turn.\n";
		std::cout << "  - " << game.movesRemaining() << " moves remaining.\n";
		std::cout << "  - " << game.canRemove() << " removes remaining.\n";
		std::cout << "  - " << game.ballsLeft() << " balls left\n";

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

		} while(!game.makeMove(move, x, y));

		std::cout << "---------------------------------------------------------------------------\n\n"; 
	}

	if(game.getScore(1) > game.getScore(2)){
		cout << "PLAYER 1 WINS!" << endl;
	} else {
		cout << "PLAYER 2 WINS!" << endl;
	}	

	return 0;
}
