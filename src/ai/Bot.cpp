#include "../../include/ai/Bot.h"

Bot::Bot(string name_str, int id): Player(id){
	name = name_str;
}

void Bot::reset(){
	states = {};
	playerBallCount = 0;
	score = 0;
}

void Bot::add_state(vector<int> state){
	states.push_back(state);
}

void Bot::feedReward(double reward) {
	for (int i = states.size() - 1; i >= 0; i--) {
		vector<int> state = states[i];

		if(!state_vals.has_key(state)){
			state_vals.add(state, 0);
		}

		state_vals.set(state, state_vals.get(state) + alpha * (gamma * reward - state_vals.get(state)));
		reward = state_vals.get(state);
	}
}

Move Bot::chooseMove(Dict<Move, vector<int> > possible_moves){
	// if possible_moves is empty then do random:
	if(state_vals.size() == 0 || (rand() % 100) <= explore_rate * 100){
		if(!quiet){ std::cout << "\t\trandom move\n"; }
		srand(time(0));
		int move_index = rand() % possible_moves.size();
		return possible_moves.index_get(move_index).first;
	}

	if(!quiet){ std::cout << "\t\tbest move of " << state_vals.size() << "\n"; }

	int greedy_index = 0;
	bool foundValue = false;
	for(int i = 0; i < possible_moves.size(); i++){
		//std::cout << "i: " << i << " : " << possible_moves.index_get(i).second[0] << endl;
		if(state_vals.has_key(possible_moves.index_get(i).second) &&
			(!foundValue ||
			state_vals.get(possible_moves.index_get(i).second) >
			state_vals.get(possible_moves.index_get(greedy_index).second))){

			greedy_index = i;	
			foundValue = true;
		}
	}
	return possible_moves.index_get(greedy_index).first;
}

Dict<vector<int>, double> Bot::getStateVals() const {
	return state_vals;	
}
