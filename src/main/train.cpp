#include <chrono>
#include "../../include/ai/TheGym.h"

int main() {
	TheGym model;
	//model.train(10);
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	//train(rounds, quiet, start_fresh)
	//model.train(1, true, true);
	model.train(100, true, false);
	std::cout << "finished training" << endl;
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " 
		<< std::chrono::duration_cast<std::chrono::seconds>(end - begin).count()
		<< "[sec]" << std::endl;

	//model.print();
	model.savePolicy();
	
}
