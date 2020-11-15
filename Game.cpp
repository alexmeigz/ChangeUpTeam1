#include "Game.h"
#include "Player.h"

using namespace std;

bool Game::canRemove() const {
	return removes < 1 && moves < 3;
}

int Game::whoseTurn() const {
	if(turnTracker)
		return 1;
	return 2;
}

int Game::getScore(int player) const {
	return players[!turnTracker].getScore();
}



string drawBall(string skel, int index, int id){
	string replacement;
	if(!id){
		replacement = to_string(id);
	} else {
		replacement = " ";
	}

	return skel.replace(index, 1, replacement);
}

void Game::displayBoard() const {
	gameboard.displayBoard();
	return;
}
