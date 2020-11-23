#include "../../include/game/GameBoard.h"
#include "../../include/game/GameParams.h"
#include "../../include/game/utility.h"
#include <functional>

using namespace std;

GameBoard::GameBoard() : board(SIZE) {
	for (int i = 0; i < SIZE; ++i) {
		// set each element to a vector of size SIZE, passing in SIZE to the constructor of GoalPost
		board[i] = vector<GoalPost>(SIZE, SIZE);
	}
}

bool GameBoard::action(int x, int y, function<bool(int x, int y)> action) {
	if (!inRange(x, SIZE) || !inRange(y, SIZE)) {
		return false;
	}
	return action(x, y);
}

int GameBoard::removeBall(int x, int y) {
	return action(x, y, [this](int x, int y){
		return board[x][y].pop();
	});
}

bool GameBoard::addBall(int player, int x, int y) {
	return action(x, y, [this, player](int x, int y){
		return board[x][y].push(player);
	});
}

Vector2D<int> GameBoard::getLayer(function<vector<int>(int itr)> col) const {
	Vector2D<int> output(SIZE);

	for (int i = 0; i < SIZE; ++i) {
		output[i] = fillVector(col(i), SIZE);
	}

	return output;
}

Vector2D<int> GameBoard::getLayer(char c, int i) const {
	switch(c){
		case 'x':
			return getLayerX(i);
		case 'y':
			return getLayerY(i);
		case 'z':
			return getLayerZ(i);
	}
	return {{-1}};
}

Vector2D<int> GameBoard::getLayerX(int x) const {
	return getLayer([this, x](int itr){
		return this->board[x][itr].getPost();
	});
}

Vector2D<int> GameBoard::getLayerY(int y) const {
	return getLayer([this, y](int itr){
		return this->board[itr][y].getPost();
	});
}

Vector2D<int> GameBoard::getLayerZ(int z) const {
	return getLayer([this, z](int itr){
		vector<int> output = vector<int>(SIZE);

		for (int y = 0; y < SIZE; ++y) {
			vector<int> col = board[itr][y].getPost();
			output[y] = fillVector(col, SIZE)[z];
		}
		
		return output;
	});
}

bool GameBoard::isFull() const {
	return getAvailableAdds().size() == 0;
}

vector<int> GameBoard::flatten() const {
	vector<int> balls;

	for (triple t : ORDERED_TRIPLES) {
		balls.push_back(getLayerY(t.first)[t.third][SIZE - t.second - 1]);
	}

	return balls;
}

vector<pair<int, int>> getAvailable(Vector2D<int> layer, function<bool(int)> condition) {
	vector<pair<int, int>> output;

	for (pair<int, int> p : ORDERED_PAIRS) {
		if (condition(layer[p.first][p.second])) {
			output.push_back(p);
		}
	}

	return output;
}

vector<pair<int, int>> GameBoard::getAvailableRemoves() const {
	// bottom layer isn't a zero (there is a value to remove)
	return getAvailable(getLayerZ(0), [](int a){ return a != 0; });
}

vector<pair<int, int>> GameBoard::getAvailableAdds() const {
	// top layer is a zero (there is a space to add)
	return getAvailable(getLayerZ(SIZE - 1), [](int a){ return a == 0; });	
}

/*
GameBoard GameBoard::operator=(const GameBoard &gb) {
	GameBoard newGameBoard = GameBoard(gb.SIZE);
	newGameBoard.board = gb.board;

	return newGameBoard;
}
*/