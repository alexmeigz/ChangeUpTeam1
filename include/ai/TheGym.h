#pragma once
#include "../game/Game.h"
#include "Bot.h"
#include "State.h"
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

		void train(int rounds, bool quiet=false, bool start_fresh=false, int print_freq=10);
		//Pre-condition: takes an int number of rounds, bools quiet and start_fresh, and int print_freq
		//Post-condition: trains on that many rounds, reporting current round on multiples of print_freq,
		//prints fewer outputs to console if quiet is true and overwrites policy file from scratch if
		//start_fresh is true

		void beQuiet();
		//Pre-condition: none
		//Post-condition: sets Bots to quiet

		State getState() const;
		//Pre-condition: none
		//Post-condition: returns member state

		void savePolicy();
		//Pre-condition: none
		//Post-condition: saves results of training in policy file

	private:
		Bot bot1;
		Bot bot2;
		Game g;
		State state;
};
