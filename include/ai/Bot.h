#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <ctime>
#include <cstdlib>
#include "Dict.h"
#include "../game/Game.h"

class Bot : public Player {
	public:
		Bot(string name_str, int id);
		//Bot(string name_str, double rand_move_pct);

		void reset(){
			states = {};
		}

		void add_state(vector<int> state){
			states.push_back(state);
		}

		void feedReward(double reward);
		//backprops rewards, updating state_vals

		Move chooseMove(Dict<Move, vector<int> > options);
		//chooses a move, randomly or greedily

		string name;

		Dict<vector<int>, double> getStateVals() const;
 
	private:

		//Member Variables
		//alpha: learning rate
		//gamma: decay rate
		//explore: how often should bot move randomly
		double alpha = 0.2;
		double gamma = 0.9;
		double explore_rate = 0.3;
		vector<vector<int> > states;
		Dict<vector<int>, double> state_vals;

};
