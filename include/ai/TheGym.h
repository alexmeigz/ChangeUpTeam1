#pragma once
#include "../game/Game.h"
#include "Bot.h"
#include <iostream>

class TheGym {
	public:
		TheGym() : 	
			bot1("bot1", 1),
			bot2("bot2", 2),
			g(){}

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
		
		void reset(){
			bot1.reset();
			bot2.reset();
			g = Game(bot1, bot2);
		}	
		void playRound();
		void train(int rounds);

		void print();

	private:
		Bot bot1;
		Bot bot2;
		Game g;
};
