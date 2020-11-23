#include <iostream>
#include <regex>
#include <vector>
#include <utility>
#include "../../include/ai/AIGame.h"
#include "../../include/game/Game.h"
#include "../../include/game/utility.h"

AIGame::AIGame(int playerId) : PLAYER_ID(playerId) {
	if (playerId == 2) {
		makeMove("", -1, -1);
	}
}

bool AIGame::makeMove(std::string move, int x, int y) {
	bool playerMove = Game::makeMove(move, x, y); //it's important to specify the game here

	while (whoseTurn() != PLAYER_ID && !finished()) {
		this->AIMakeMove();    
	}
	
	return playerMove;
}

void AIGame::AIMakeMove(){
	vector<pair<int, int> > availableAdds = Game::availableAdds(),
		availableRemoves = Game::availableRemoves();
	int addSize = availableAdds.size();

	// available adds now contains all possible move pairs
	availableAdds.insert(std::end(availableAdds), std::begin(availableRemoves), std::end(availableRemoves));

	int num = rand() % availableAdds.size();

	std::string computerMove = num < addSize ? "ADD" : "REMOVE";
	int x = availableAdds[num].first,
	    y = availableAdds[num].second;

	//std::cout << computerMove << " " << x << "," << y << std::endl;
	Game::makeMove(computerMove, x, y);
}

void AIGame::displayBoard() const {
	string player1Name = PLAYER_ID == 1 ? "Player" : "Computer";
	string player2Name = PLAYER_ID == 2 ? "Player" : "Computer";

	string display = (
		"               *     *     *\n"
		"               *     *     *              Current Score\n"
		"               * --- * --- *              " + player1Name + ": O : " + to_string(getScore(1)) + "\n"  
		"           *  /  *  /  *  /               " + player2Name + ": X : " + to_string(getScore(2)) + "\n" 
		"           * /   * /   * /\n"
		"           * --- * --- *                  It is " + (whoseTurn() == 1 ? player1Name : player2Name) + "'s turn.\n" 
		"       *  /  *  /  *  /                     - " + to_string(movesRemaining()) + " moves remaining.\n"
		"       * /   * /   * /                      - " + to_string(canRemove()) + " remove remaining.\n"
		"       * --- * --- *                        - " + to_string(ballsLeft()) + " balls left.\n"
	);
	
	vector<int> ball_indices;
	for(int i = 0; i < display.size(); i++){
		if(display[i] == '*'){
			ball_indices.push_back(i);
		}
	}

	vector<int> balls = gameboard.flatten();

	for(int i = 0; i < 27; i++){
		display = drawBall(display, ball_indices[i], balls[i]);
	}

	cout << display << endl;
}