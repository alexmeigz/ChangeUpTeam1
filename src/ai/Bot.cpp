#include "../../include/ai/Bot.h"

using namespace std;

Bot::Bot(string name_str, int id): Player(id){
	name = name_str;
}

void Bot::reset(){
	states = {};
	playerBallCount = 0;
	score = 0;
}

void Bot::add_state(string state){
	states.push_back(state);
}

void Bot::feedReward(double reward) {
	for (int i = states.size() - 1; i >= 0; i--) {
		string state = states[i];

		if(state_vals.find(state) == state_vals.end()){
			state_vals[state] = 0;
		}

		state_vals[state] += alpha * (gamma * reward - state_vals[state]);
		reward = state_vals[state];
	}
}

Move Bot::chooseMove(unordered_map<string, Move> possible_moves){
	// if possible_moves is empty then do random:
	if(state_vals.size() == 0 || (rand() % 100) <= explore_rate * 100){
		if(!quiet){ std::cout << "\t\trandom move\n"; }

		srand(time(0));
		unordered_map<string, Move>::iterator item = possible_moves.begin();
		int move_index = rand() % possible_moves.size();
		advance(item, move_index);

		return item->second;
	}

	if(!quiet){ std::cout << "\t\tbest move of " << state_vals.size() << "\n"; }

	string g_key;
	bool foundValue = false;

	for(pair<string, Move> state_move : possible_moves){
		if(state_vals.find(state_move.first) != state_vals.end() &&
			(!foundValue ||
			state_vals[state_move.first] > state_vals[g_key])){

			g_key = state_move.first;	
			foundValue = true;
		}
	}
	return possible_moves[g_key];
}

unordered_map<string, double> Bot::getStateVals() const {
	return state_vals;	
}

vector<string> Bot::getStates() const {
	return states;
}
