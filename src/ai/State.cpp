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
            state[i] == '1';
        }
    }
    return state;
}

bool State::has_key(string state) {
    return state_vals.find(state) != state_vals.end() 
        || state_vals.find(invert(state)) != state_vals.end();
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
    state_vals[state] = val;
}

int State::size() {
    return state_vals.size();
}

void State::savePolicy() {
	ofstream file("src/ai/states.csv", ios::app);
    
    for(string state : newAdds) {
        file << state << "," << get(state) << endl;
    }

	file.close();
    newAdds.clear();
}

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
