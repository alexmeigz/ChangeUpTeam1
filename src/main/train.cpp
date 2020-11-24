#include "../../include/ai/TheGym.h"

int main() {
	TheGym model;
	//model.train(10);
	model.train(1, true, false);
    model.savePolicy();
}
