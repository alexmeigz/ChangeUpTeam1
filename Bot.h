#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <ctime>
#include <cstdlib>
#include "Game.h"

struct Move {
	std::string add_rem;
	int x;
	int y;
};

class Bot : public Player {
	public:
		Bot(string name_str);
		std::string name;
	private:
		//Move chooseMove(vector<pair<int, int> > av_add, vector<pair<int, int> > av_rem, vector<int> current_state);	
		//chooses a move, randomly or greedily
		void feedReward(double reward);
		//backprops rewards, updating state_vals
		double giveReward();
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
		std::vector<std::vector<int> > states;
		std::unordered_map<std::vector<int>, double> state_vals;
};
