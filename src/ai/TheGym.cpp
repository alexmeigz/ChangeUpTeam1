#include "../../include/ai/TheGym.h"
#include "../../include/ai/Dict.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

//test comment

TheGym::TheGym() : 	
		bot1("bot1", 1),
		bot2("bot2", 2),
		g(){}

void TheGym::giveReward(){
	if(g.winner() == 1){
		bot1.feedReward(1);
		bot2.feedReward(0);
	}
	else if(g.winner() == 2){
		bot1.feedReward(0);
		bot2.feedReward(1);
	}
	else {
		bot1.feedReward(0.1);
		bot2.feedReward(0.5);
	}
}

void TheGym::reset(){
	bot1.reset();
	bot2.reset();
	g = Game(bot1, bot2);
}	

void print_states(Bot bot){
	//vector<vector<int> > states;
	vector<string> states;
	states = bot.getStates();

	for(int i = 0; i < states.size(); i++){
		for(int j = 0; j < 27; j++){
			cout << states[i][j] << " ";
		}
		cout << endl;
	}
}

void TheGym::playRound(){
	double winner;
	//Dict<Move, vector<int> > options;
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
	giveReward();

	print_states(bot1);

	reset();
	std::cout << "finished round\n";
}

void TheGym::playRound(bool quiet){
	double winner;
	//Dict<Move, vector<int> > options;
	std::unordered_map<std::string, Move> options;
	Move next_move;
	
	beQuiet();

	while(!g.finished()) {
		while(!g.finished() && g.whoseTurn() == 1){
			options = g.get_possibilities();
			next_move = bot1.chooseMove(options);
			g.makeMove(next_move.add_rem, next_move.x, next_move.y);
			bot1.add_state(g.flatten());
		}
		while(!g.finished() && g.whoseTurn() == 2){
			options = g.get_possibilities();
			next_move = bot2.chooseMove(options);
			g.makeMove(next_move.add_rem, next_move.x, next_move.y);
			bot2.add_state(g.flatten());
		}
	}
	giveReward();
	//print_states(bot1);
	reset();
}

void TheGym::train(int rounds, bool quiet, bool start_fresh){
	std::cout << "Starting training...\n";
	if(!start_fresh){
		bot1.readPolicy("src/ai/bot1.txt");
		bot2.readPolicy("src/ai/bot2.txt");
	}
	for(int i = 0; i < rounds; i++){
		if((i + 1) % 10 == 0){
			std::cout << "On round: " << i + 1;
			std::cout << endl;
		}
		if(quiet){
			playRound(quiet);
		}
		else {
			playRound();
		}
	}
}

/*
void printBot(Bot bot) {
	ofstream file ("src/ai/" + bot.name + ".json");

	std::cout << bot.name << " has " << bot.getStateVals().size() << " state-val pairs to output.\n";

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
*/

void savePolicy(Bot bot){
	std::cout << bot.name << " has " << bot.getStateVals().size() << " state-val pairs to output.\n";
	ofstream file("src/ai/" + bot.name + ".txt");
	//Dict<vector<int>, double> dict = bot.getStateVals();
	std::unordered_map<std::string, double> dict = bot.getStateVals();
	file << dict.size() << endl;
	//for(int i = 0; i < dict.size(); i++){
	for(pair<std::string, double> sv_pair : dict){
		//pair<vector<int>, double> sv_pair = dict.index_get(i);
		//std::cout << sv_pair.second << endl;
		file << sv_pair.second << " ";
		for(int j = 0; j < 27; j++){
			file << sv_pair.first[j] << " ";
		}
		file << endl;
	}
	file.close();
}

void Bot::readPolicy(string filename){
	ifstream file(filename);
	state_vals.empty();
	double dummy_val;
	string dummy_state = "";
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
		//state_vals.add(dummy_state, dummy_val);
		state_vals[dummy_state] = dummy_val;
	}
	file.close();
}

void TheGym::beQuiet(){
	bot1.quiet = true;
	bot2.quiet = true;
}

void TheGym::print() {
	savePolicy(bot1);
	savePolicy(bot2);
	//printBot(bot1);
	//printBot(bot2);
}
