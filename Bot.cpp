#include "Bot.h"

void Bot::feedReward(double reward) {

}

double Bot::giveReward() {
    return 0;
}

/*
Move Bot::chooseMove(vector<pair<int, int> > av_add, 
	vector<pair<int, int> > av_rem, 
	vector<int> current_state){

    int exploration_rate = 0;

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
*/