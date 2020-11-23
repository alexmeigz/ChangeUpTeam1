#include "../../include/ai/TheGym.h"

void TheGym::playRound(){
	double winner;
	Dict<Move, vector<int> > options;
	Move next_move;

	while(!g.finished()) {
		while(!g.finished() && g.whoseTurn() == 1){
			options = g.get_possibilities();
			next_move = bot1.chooseMove(options);
			g.makeMove(next_move.add_rem, next_move.x, next_move.y);
			bot1.add_state(g.flatten());
		}

		winner = g.winner();
		if(winner > -1){
			giveReward();
		} else {
			while(!g.finished() && g.whoseTurn() == 2){
				options = g.get_possibilities();
				next_move = bot2.chooseMove(options);
				g.makeMove(next_move.add_rem, next_move.x, next_move.y);
				bot2.add_state(g.flatten());
			}
		}

		if(winner > -1){
			giveReward();
		}
	}
	reset();
}

void TheGym::train(int rounds){
	for(int i = 0; i < rounds; i++){
		playRound();
	}
}
