#pragma once
#include "Game.h"
#include "Bot.h"
#include <iostream>

class State {
	public:
		State () {
			g = new Game(SIZE, 
				NUM_PLAYERS, 
				MAX_BALL, 
				WINNING_SCORE, 
				MOVES_PER_TURN, 
				MOVES_FIRST_TURN, 
				REMOVES_PER_TURN);
		}



		~State() {
			delete g;
		}

		void giveReward(){
			if(g.winner() == 1){
				bot1.feedReward(1);
				bot2.feedReward(0);
			}
			else if(g.winner() == 2){
				bot1.feedReward(0);
				bot2.feedReward(1);
			}
			else {
				bot1.feedReward(0.1);
				bot2.feedReward(0.5);
			}
		}

	private:
		Game * g;
		Bot bot1 = Bot("bot 1");
		Bot bot2 = Bot("bot 2");
};
