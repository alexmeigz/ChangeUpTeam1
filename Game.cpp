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
	//turnTracker is true if it is player1's turn
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

//in y layer
int layerDiagScore(char c, int i) {
	vector<vector<int> > layer = gameboard.getLayer(c, i);
	vector<int> diag1, diag2;

	diag1.push_back(layer[0][0]);
	diag1.push_back(layer[1][1]);
	diag1.push_back(layer[2][2]);
	diag1.push_back(layer[0][2]);
	diag1.push_back(layer[1][1]);
	diag1.push_back(layer[2][0]);

	int diag1s = isSame(diag1);
	int diag2s = isSame(diag2);
	
	return diag1s + diag2s;
}

//void 

bool isSame(vector<int> v){
	return v[0] == v[1] && v[1] == v[2];
}
