#include "../../include/ai/Bot.h"
#include "../../include/ai/State.h"

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

vector<string> Bot::getStates() const {
	return states;
}

void Bot::feedReward(State &stateDict, double reward) {
	for (int i = states.size() - 1; i >= 0; i--) {
		string state = states[i];

		if(!stateDict.has_key(state)){
			stateDict.set(state, 0, playerGetId());
		}

		double current = stateDict.get(state, playerGetId());
		stateDict.set(state, current + alpha * (gamma * reward - current), playerGetId());
		reward = stateDict.get(state, playerGetId());
	}
}

Move Bot::chooseMove(State &stateDict, Dict<Move, string> possible_moves){
	// if possible_moves is empty then do random:
	if(stateDict.size() == 0 || (rand() % 100) <= explore_rate * 100){
		std::cout << "\t\trandom move\n";
		srand(time(0));
		int move_index = rand() % possible_moves.size();
		return possible_moves.index_get(move_index).first;
	}

	std::cout << "\t\tbest move of " << stateDict.size() << "\n";

	int greedy_index = -1;
	for(int i = 0; i < possible_moves.size(); i++){
		//std::cout << "i: " << i << " : " << possible_moves.index_get(i).second[0] << endl;
		if(	stateDict.has_key(possible_moves.index_get(i).second) &&
			(greedy_index == -1 ||
			stateDict.get(possible_moves.index_get(i).second, playerGetId()) >
			stateDict.get(possible_moves.index_get(greedy_index).second, playerGetId()))){
			
			greedy_index = i;	
		}
	}
	return possible_moves.index_get(greedy_index).first;
}
