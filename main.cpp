#include <iostream>
#include <vector>
#include <string>
#include "Game.h"

int main() {
	GameBoard dummy(3);
	dummy.displayBoard();
	dummy.addBall(1, 0, 0);
	dummy.displayBoard();

	return 0;
}
