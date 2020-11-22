#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "Game.h"

struct Move {
	string add_rem;
	int x;
	int y;
};

class Bot : public Player {
	public:
		Bot(string name_str);
		string name;
	private:
		Move chooseMove();	
		//chooses a move, randomly or greedily
		void feedReward();
		//backprops rewards, updating state_vals
		void giveReward();
		//distributes rewards at the end of the game with feedReward
		void reset();
		//resets states to empty
		
		//Member Variables
		//alpha: learning rate
		//gamma: decay rate
		//explore: how often should bot move randomly
		double alpha = 0.2;
		double gamma = 0.9;
		double explore_rate = 0.3;
		vector<vector<int> > states;
		unordered_map<vector<int>, double> state_vals;

};
