#include "Bot.h"

Move Bot::chooseMove(unordered_map<Move, vector<int> > possible_moves){
	/*
	vector<Move> possible_moves;
	for(int i = 0; i < av_add.size(); i++){
		Move dummy = {"ADD", av_add[i].first, av_add[i].second};
		possible_moves.push_back(dummy);
	}
	for(int i = 0; i < av_rem.size(); i++){
		Move dummy = {"REMOVE", av_rem[i].first, av_rem[i].second};
		possible_moves.push_back(dummy);
	}
	*/

	if((rand() % 100) <= exploration_rate * 100){
		//make a random move
		srand(time(0));
		int move_index = rand() % possible_moves.size();
		int counter = 0;
		for(pair<Move, vector<int> option: possible_moves){
			if(counter == move_index){
				return option.first;
			}
			counter++;
		}
	}

	pair<Move, vector<int> > greedy_choice;
	bool on_first_pair = true;
	for(pair<Move, vector<int> option: possible_moves){
		if(on_first_pair){
			greedy_choice = option;
			on_first_pair = false;
		} else {
			if(state_vals[option.second] > state_vals[greedy_choice.second]){
				greedy_choice = option;
			}
		}
	}

	return greedy_choice.first;
	
}
