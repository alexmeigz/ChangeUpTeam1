#include "../../include/ai/Bot.h"

Bot::Bot(string name_str, int id, int maxBalls): Player(id){
	name = name_str;
}

/*
Bot::Bot(string name_str, double rand_move_pct){
	name = name_str;
	explore_rate = rand_move_pct;
}
*/

void Bot::feedReward(double reward) {
	for (int i = states.size() - 1; i >= 0; i--) {
		vector<int> state = states[i];

		if(state_vals.has_key(state)){
			state_vals.add(state, 0);
		}

		state_vals.get(state) += alpha * (gamma * reward - state_vals.get(state));
		reward = state_vals.get(state);
	}
}

Move Bot::chooseMove(Dict<Move, vector<int> > possible_moves){

	if((rand() % 100) <= explore_rate * 100){
		//make a random move
		srand(time(0));
		int move_index = rand() % possible_moves.size();
		return possible_moves.index_get(move_index).first;
	}

	int greedy_index = 0;
	for(int i = 1; i < possible_moves.size(); i++){
		if(state_vals.get(possible_moves.index_get(i).second) >
			state_vals.get(possible_moves.index_get(greedy_index).second)){
			greedy_index = i;	
		}
	}

	return possible_moves.index_get(greedy_index).first;

}

