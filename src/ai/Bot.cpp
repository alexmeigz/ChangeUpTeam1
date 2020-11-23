#include "../../include/ai/Bot.h"

Bot::Bot(string name_str, int id): Player(id){
	name = name_str;
}

void Bot::feedReward(double reward) {
	for (int i = states.size() - 1; i >= 0; i--) {
		vector<int> state = states[i];

		if(state_vals.has_key(state)){
			state_vals.add(state, 0);
		}

		state_vals.set(state, state_vals.get(state) + alpha * (gamma * reward - state_vals.get(state)));
		reward = state_vals.get(state);
	}
}

Move Bot::chooseMove(Dict<Move, vector<int> > possible_moves){

	// if possible_moves is empty then do random:
	if(state_vals.size() == 0 || (rand() % 100) <= explore_rate * 100){
		std::cout << "\t\trandom move\n";
		srand(time(0));
		int move_index = rand() % possible_moves.size();
		return possible_moves.index_get(move_index).first;
	}

	std::cout << "\t\tbest move of " << state_vals.size() << "\n";

	int greedy_index = 0;
	for(int i = 0; i < possible_moves.size(); i++){
		if(state_vals.get(possible_moves.index_get(i).second) >
			state_vals.get(possible_moves.index_get(greedy_index).second)){
			greedy_index = i;	
		}
	}

	return possible_moves.index_get(greedy_index).first;

}


Dict<vector<int>, double> Bot::getStateVals() const {
	return state_vals;	
}