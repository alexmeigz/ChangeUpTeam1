#pragma once
#include "../game/Game.h"
#include "Bot.h"
#include <iostream>

class TheGym {
	public:
		TheGym();
		//default constructor, starts with bot1 and bot2

		void giveReward();
		//Pre-condition: none
		//Post-condition: distributes reward, updating bot policies

		void reset();
		//Pre-condition: none
		//Post-condition: resets bots and game

		void playRound();
		//Pre-condition: none
		//Post-condition: plays one training round

		void playRound(bool quiet);
		//Pre-condition: none
		//Post-condition: plays one training round without printing individual turns

		void train(int rounds, bool quiet=false);
		//Pre-condition: takes an int number of rounds and bool quiet (default false)
		//Post-condition: plays that many number of rounds, with fewer
		//prints if quiet is true

		void beQuiet();
		//Pre-condition: none
		//Post-condition: sets Bots to quiet

		void print();
		//Pre-condition: none
		//Post-condition: prints both bots

	private:
		Bot bot1;
		Bot bot2;
		Game g;
};
