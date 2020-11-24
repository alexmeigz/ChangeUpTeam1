#include "../../include/ai/TheGym.h"

int main() {
	TheGym model;
	model.train(1000, true);
	model.print();
}
