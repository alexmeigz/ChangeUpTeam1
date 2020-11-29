#include "../../include/ai/Bot.h"
#include "../../include/ai/State.h"

using namespace std;

Bot::Bot(string name_str, int id): Player(id){
	name = name_str;
	for(int i = 0; i < 27; i++){
		rotate_indices[i] =
			((i % 9) % 3) * 9 +
			((i / 3) % 3) * 3 +
			(2 - (i / 9));
	}
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
	for(int i = 0; i < states.size(); i++){
		//cout << states[i] << endl;
	}
	string state;
	for (int i = states.size() - 1; i >= 0; i--) {
		state = states[i];

/*
//<<<<<<< HEAD
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

//=======
*/
		//cout << "updating dict entry" << endl;
		if(!stateDict.has_key(state, playerGetId())){
			stateDict.set(state, 0, playerGetId());
		}

		stateDict.set(state, 
			stateDict.get(state, playerGetId()) +
				alpha * (gamma * reward - stateDict.get(state, playerGetId())),
			 playerGetId());
		//cout << "updated" << endl;
		reward = stateDict.get(state, playerGetId());
	}
}

//Move Bot::chooseMove(State &stateDict, Dict<Move, string> possible_moves){
Move Bot::chooseMove(State &stateDict, unordered_map<string, Move> possible_moves){
	// if policy is empty then do random:
	srand(time(0));
	//cout << "options size: " << possible_moves.size() << endl;
	if(possible_moves.size() == 0){
		cerr << "no possible moves ya dingus" << endl;
		exit(1);
	}

	if(stateDict.size() == 0 || (rand() % 100) <= explore_rate * 100){
		//std::cout << "\t\trandom move\n";
//>>>>>>> b3c986d216dfea0a75b59fbe06d415840d9d0716
		unordered_map<string, Move>::iterator item = possible_moves.begin();
		
		int move_index = rand() % possible_moves.size();
		advance(item, move_index);

		return item->second;
	}

	//std::cout << "\t\tbest move of " << stateDict.size() << "\n";

//<<<<<<< HEAD
	string g_key;
	bool foundValue = false;

	for(pair<string, Move> state_move : possible_moves){
		if(stateDict.has_key(state_move.first, playerGetId()) &&
			(!foundValue ||
			stateDict.get(state_move.first, playerGetId()) >
			stateDict.get(g_key, playerGetId()))){
			//state_vals[state_move.first] > state_vals[g_key])){

			g_key = state_move.first;	
			foundValue = true;
/*
//=======
	int greedy_index = -1;
	for(int i = 0; i < possible_moves.size(); i++){
		//std::cout << "i: " << i << " : " << possible_moves.index_get(i).second[0] << endl;
		if(	stateDict.has_key(possible_moves.index_get(i).second, playerGetId()) &&
			(greedy_index == -1 ||
			stateDict.get(possible_moves.index_get(i).second, playerGetId()) >
			stateDict.get(possible_moves.index_get(greedy_index).second, playerGetId()))){
			
			greedy_index = i;	
>>>>>>> b3c986d216dfea0a75b59fbe06d415840d9d0716
*/
		}
	}
	return possible_moves[g_key];
}

/*
unordered_map<string, double> Bot::getStateVals() const {
	return state_vals;	
}
*/

/*
vector<string> Bot::getStates() const {
	return states;
}
*/

string Bot::rotate(string state){
	string rotated = state;
	for(int i = 0; i < 27; i++){
		rotated[rotate_indices[i]] = state[i];
	}
	return rotated;
}
