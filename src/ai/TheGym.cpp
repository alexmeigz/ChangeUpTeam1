#include "../../include/ai/TheGym.h"
#include "../../include/ai/Dict.h"
#include "../../include/game/utility.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

TheGym::TheGym() : 	
		bot1("bot1", 1),
		bot2("bot2", 2),
		g(){}

void TheGym::giveReward(){
	if(g.winner() == 1){
		bot1.feedReward(state, 1);
		bot2.feedReward(state, 0);
	}
	else if(g.winner() == 2){
		bot1.feedReward(state, 0);
		bot2.feedReward(state, 1);
	}
	else {
		bot1.feedReward(state, 0.1);
		bot2.feedReward(state, 0.5);
	}
}

void TheGym::reset(){
	bot1.reset();
	bot2.reset();
	g = Game(bot1, bot2);
}	

void print_states(Bot bot){
	vector<string> states;
	states = bot.getStates();

	for(int i = 0; i < states.size(); i++){
		for(int j = 0; j < 27; j++){
			cout << states[i][j] << " ";
		}
		cout << endl;
	}
}

/*
void TheGym::playRound(){
	double winner;
	std::unordered_map<std::string, Move> options;
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
}
*/

void TheGym::playRound(bool quiet){
	double winner;
	std::unordered_map<std::string, Move> options;
	Move next_move;

	while(!g.finished()) {
		if (!quiet) std::cout << "bot 1's turn:\n";
		while(!g.finished() && g.whoseTurn() == 1){
			options = g.get_possibilities();
			if (!quiet) std::cout << "\tchoosing move\n";
			next_move = bot1.chooseMove(state, options);
			if (!quiet) std::cout << "\tmoving\n";
			g.makeMove(next_move.add_rem, next_move.x, next_move.y);
			bot1.add_state(g.flatten());
		}
		if (!quiet) std::cout << "bot 2's turn:\n";
		while(!g.finished() && g.whoseTurn() == 2){
			options = g.get_possibilities();
			if (!quiet) std::cout << "\tchoosing move\n";
			next_move = bot2.chooseMove(state, options);
			if (!quiet) std::cout << "\tmoving\n";
			g.makeMove(next_move.add_rem, next_move.x, next_move.y);
			bot2.add_state(g.flatten());
		}
	}
	giveReward();
	reset();
}

void TheGym::train(int rounds, bool quiet, bool start_fresh){
	std::cout << "Starting training...\n";
	if(!start_fresh){
		state.readPolicy();
	}
	for(int i = 0; i < rounds; i++){
		
		if((i + 1) % 10 == 0){
			std::cout << "On round: " << i + 1;
			std::cout << endl;
		}
		
		/*
		if(i != 0 && i % 1000 == 0){
			savePolicy();
		}
		*/

		playRound(quiet);
	}
}

/*
void savePolicy(Bot bot){
	std::cout << bot.name << " has " << bot.getStateVals().size() << " state-val pairs to output.\n";

	ofstream file("src/ai/" + bot.name + ".txt");
	std::unordered_map<std::string, double> dict = bot.getStateVals();
	file << dict.size() << endl;
	for(pair<std::string, double> sv_pair : dict){
		file << sv_pair.second << " ";
		file << sv_pair.first << endl;
	}
	file.close();
}
*/

/*
void Bot::readPolicy(string filename){
	ifstream file(filename);
	state_vals.empty();
	double dummy_val;
	string dummy_state;
	
	for(int i = 0; i < 27; i++){
		dummy_state += " ";
	}
	
	int pair_count;
	file >> pair_count;
	for(int i = 0; i < pair_count; i++){
		file >> dummy_val;
		for(int j = 0; j < 27; j++){
			file >> dummy_state[j];
		}
		file >> dummy_state;
		state_vals[dummy_state] = dummy_val;
	}
	file.close();
}
*/

void TheGym::beQuiet(){
	bot1.quiet = true;
	bot2.quiet = true;
}

State TheGym::getState() const {
	return state;
}

void TheGym::savePolicy() {
	cout << "state_vals size: " << state.size() << endl;
	state.savePolicy();
}
