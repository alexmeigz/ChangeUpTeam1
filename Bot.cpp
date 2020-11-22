#include "Bot.h"

void Bot::feedReward(double reward) {
    for (int i = states.size() - 1; i >= 0; --i) {
        vector<int> state = states[i];

        if (state_vals.find(state) != state_vals.end()) {
            state_vals[state] = 0;
        }

        state_vals[state] += alpha * (gamma * reward - state_vals[state]);
        reward = state_vals[state];
    }
}

double Bot::giveReward() {
    
}