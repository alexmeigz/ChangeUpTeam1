#include "../../include/ai/TheGym.h"

int main() {
	TheGym model;
	//model.train(10);
	model.train(10, true);
	model.print();
}
