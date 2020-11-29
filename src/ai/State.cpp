#include "../../include/ai/State.h"
#include "fstream"
#include <string>
#include <iostream>
#include <regex>
#include <sstream>
/*

ALL KEYS ARE BASED FOR 1 TO BE CURRENT PLAYER

*/

string invert(string state) {
    for (int i = 0; i < state.size(); ++i) {
        if (state[i] == '1') {
            state[i] = '2';
        }
        else if (state[i] == '2') {
            state[i] = '1';
        }
    }
    return state;
}

bool State::has_key(string state, int player) {
    if (player == 2) {
        state = invert(state);
    }

    return state_vals.find(state) != state_vals.end();
}

double State::get(string state, int player = 1) {
    if (player == 2) {
        state = invert(state);
    }

    return state_vals[state];
}

void State::set(string state, double val, int player, bool readFromFile) {
    if (player == 2) {
        state = invert(state);
    }
    /*
    if (has_key(state, player) && !readFromFile) {
        newAdds.push_back(state);
        if (newAdds.size() == 1000) {
            savePolicy();
        }
    }
    */
    state_vals[state] = val;
}

int State::size() {
    return state_vals.size();
}

void State::savePolicy() {
	std::cout << "saving " << state_vals.size() << " state-val pairs.\n";
	ofstream file("src/ai/policy.txt");

   	file << state_vals.size() << endl;
	for(pair<std::string, double> sv_pair : state_vals){
		file << sv_pair.second << " ";
		file << sv_pair.first << endl;
	}

	file.close();
}

void State::readPolicy(){
	ifstream file("src/ai/policy.txt");
	double dummy_val;
	string dummy_state;
	int pair_count;
	file >> pair_count;

	for(int i = 0; i < pair_count; i++){
		file >> dummy_val;
		file >> dummy_state;
		state_vals[dummy_state] = dummy_val;
	}
	file.close();
}

/*
void State::readPolicy(){
	ifstream file("src/ai/states.csv");
	
	std::regex input_rgx("^([012]{27}),([\\d\\.e-]*)$");
	std::smatch matches;
    std::string line;
    while(getline(file, line)) {
        std::regex_search(line, matches, input_rgx);

        string state = matches.str(1);

        double value;
        istringstream os(matches.str(2));
        os >> value;

        set(state, value, 1, true);
    }

	file.close();
}
*/
