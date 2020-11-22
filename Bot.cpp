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
    
}
Move Bot::chooseMove(vector<pairs<int, int> > av_add, 
	vector<pairs<int, int> > av_rem, 
	vector<int> current_state){
	vector<Move> possible_moves;
	for(int i = 0; i < av_add.size(); i++){
		Move dummy = {"ADD", av_add[i].first, av_add[i].second};
		possible_moves.push_back(dummy);
	}
	for(int i = 0; i < av_rem.size(); i++){
		Move dummy = {"REMOVE", av_rem[i].first, av_rem[i].second};
		possible_moves.push_back(dummy);
	}

	srand(time(0));
	if((rand() % 100) <= exploration_rate * 100){
		//make a random move
		int move_index = rand() % possible_moves.size();
		return possible_moves[move_index];
	}
	
	//choose greedy move
	
}
