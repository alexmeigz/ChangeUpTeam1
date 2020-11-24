#include "../../include/ai/State.h"

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

bool State::has_key(string state, int player) {
    if (player == 2) {
        state = invert(state);
    }

    return state_vals.find(state) != state_vals.end();
}

double State::get(string state, int player) {
    if (player == 2) {
        state = invert(state);
    }

    return state_vals[state];
}

void State::set(string state, double val, int player) {
    if (player == 2) {
        state = invert(state);
    }

    state_vals[state] = val;
}

int State::size() {
    return state_vals.size();
}