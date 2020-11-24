#include "../../include/ai/TheGym.h"
#include "../../include/ai/Dict.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
void TheGym::playRound(){
	double winner;
	Dict<Move, vector<int> > options;
	Move next_move;

	while(!g.finished()) {
		std::cout << "bot 1's turn:\n";
		while(!g.finished() && g.whoseTurn() == 1){
			options = g.get_possibilities();
			std::cout << "\tchoosing move\n";
			next_move = bot1.chooseMove(options);
			std::cout << "\tmoving\n";
			g.makeMove(next_move.add_rem, next_move.x, next_move.y);
			bot1.add_state(g.flatten());
		}
		std::cout << "bot 2's turn:\n";
		while(!g.finished() && g.whoseTurn() == 2){
			options = g.get_possibilities();
			std::cout << "\tchoosing move\n";
			next_move = bot2.chooseMove(options);
			std::cout << "\tmoving\n";
			g.makeMove(next_move.add_rem, next_move.x, next_move.y);
			bot2.add_state(g.flatten());
		}
	}
	giveReward();
	reset();
	std::cout << "finished round\n";
}

void TheGym::train(int rounds){
	std::cout << "Staring training...\n";
	for(int i = 0; i < rounds; i++){
		std::cout << "\nRound: " << i << endl;
		playRound();
	}
}

void printBot(Bot bot) {
	ofstream file ("C:/Users/Alex3/Desktop/ROBOTICS SOFTWARE/Project/ChangeUpTeam1/" + bot.name + ".json");

	std::cout << bot.name << " has " << bot.getStateVals().size() << " number of states to output.\n";

	file << "[\n";

	Dict<vector<int>, double> dict = bot.getStateVals();
	for (int i = 0; i < dict.size(); ++i) {
		pair<vector<int>, double> val = dict.index_get(i);

		file << "\t{\n";
		file << "\t\t\"state\": [" << (val.first.size() ? to_string(val.first[0]) : "");
		for (int j = 1; j < val.first.size(); ++j) {
			file << "," << val.first[j];	
		}

		file << "],\n\t\t\"val\": " << val.second << endl;
		file << "\t}" << (i + 1 < dict.size() ? "," : "") << "\n";
	}

	file << "]\n";

	file.close();
}

void TheGym::print() {
	printBot(bot1);
	printBot(bot2);
}