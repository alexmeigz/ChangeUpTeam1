#include <chrono>
#include "../../include/ai/TheGym.h"

const int TRAINING_ROUNDS = 1000;
const int PRINT_ROUND_FREQ = 50;
const bool QUIET = true;
const bool START_FRESH = false;

int main(){
	TheGym model;
		
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	model.train(TRAINING_ROUNDS, QUIET, START_FRESH, PRINT_ROUND_FREQ);
	
	std::cout << "finished training" << endl;

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " 
		<< std::chrono::duration_cast<std::chrono::seconds>(end - begin).count()
		<< "[sec]" << std::endl;

	model.savePolicy();
	
}
