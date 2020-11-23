#include "Bot.h"


void Bot::feedReward(double reward) {
	for (int i = states.size() - 1; i >= 0; i--) {
		vector<int> state = states[i];

		if(state_vals.has_key(state)){
			state_vals.add(state, 0);
		}

		state_vals[state] += alpha * (gamma * reward - state_vals[state]);
		reward = state_vals[state];
	}
}

double Bot::giveReward() {
	return 0;    
}

Move Bot::chooseMove(Dict<Move, vector<int> > possible_moves){

	if((rand() % 100) <= exploration_rate * 100){
		//make a random move
		srand(time(0));
		int move_index = rand() % possible_moves.size();
		return possible_moves.index_get(move_index).first;
	}

	int greedy_index = 0;
	for(int i = 1; i < possible_moves.size(); i++){
		if(state_vals.get(possible_moves.index_get(i).second) >
			state_vals.get(possible_moves.index_get(greedy_choice.second))){
			greedy_index = i;	
		}
	}

	return possible_moves.index_get(greedy_index).first;

}
