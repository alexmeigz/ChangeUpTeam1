#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class State {
	public:
		bool has_key(string);
		//Pre-condition: takes a string state
		//Post-condition: returns if state_vals contains that state

		double get(string, int);
		//Pre-condition: takes a string state and int player ID
		//state must be an existing key
		//Post-condition: returns the associated value of state

		void set(string, double, int);
		//Pre-condition: takes string state, new value for that state, and int player ID
		//Post-condition: sets the state's value to the double, inverting as necessary for player ID

		int size();
		//Pre-condition: none
		//Post-condition: returns size of policy dictionary

		void readPolicy();
		//Pre-condition: none
		//Post-condition: reads policy file into state_vals

		void savePolicy();
		//Pre-condition: none
		//Post-condition: saves state_vals in policy file

	private:
		unordered_map<string, double> state_vals; //move policy; matches game states to its value
};
