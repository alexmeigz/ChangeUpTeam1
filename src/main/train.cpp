#include "../../include/ai/TheGym.h"

const int TRAINING_ROUNDS = 3000;
const int PRINT_ROUND_FREQ = 50;
const bool QUIET = true;
const bool START_FRESH = false;

int main(){
	TheGym model;
	model.train(TRAINING_ROUNDS, QUIET, START_FRESH, PRINT_ROUND_FREQ);
	return 0;	
}
