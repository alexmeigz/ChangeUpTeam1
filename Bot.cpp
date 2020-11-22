#include "Bot.h"

void Bot::feedReward(double reward) {
    for (int i = states.size() - 1; i >= 0; --i) {
        vector<int> state = states[i];

        if (state_vals.find(state) != state_vals.end()) {
            state_vals[state] = 0;
        }

        state_vals[state] += alpha * (gamma * reward - state_vals[state]);
        reward = state_vals[state];
    }
}

double Bot::giveReward() {
	return 0;    
}

Move Bot::chooseMove(unordered_map<Move, vector<int> > possible_moves){

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
