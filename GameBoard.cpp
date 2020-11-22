#include "GameBoard.h"
#include <functional>

GameBoard::GameBoard(const int size) : SIZE(size), board(size) {
	for (int i = 0; i < this->SIZE; ++i) {
		// set each element to a vector of size SIZE, passing in SIZE to the constructor of GoalPost
		this->board[i] = std::vector<GoalPost>(this->SIZE, this->SIZE);
	}

	numBalls = 0;
}

int GameBoard::removeBall(int x, int y) {
	if (x < 0 || x >= this->SIZE || y < 0 || y >= this->SIZE) {
		return false;
	}

	bool result =  this->board[x][y].pop();

	if (result) {
		--numBalls;
	}

	return result;
}

bool GameBoard::addBall(int player, int x, int y) {
	if (x < 0 || x >= this->SIZE || y < 0 || y >= this->SIZE) {
		return false;
	}

	bool result = this->board[x][y].push(player);

	if (result) {
		++numBalls;
	}

	return result;
}

std::vector<int> GameBoard::fillPost(const std::vector<int> &post) const {
	// copy over the filled in values
	std::vector<int> output = post;

	// fill in the rest with 0's
	output.resize(this->SIZE, 0);

	return output;
}

Vector2D<int> GameBoard::getLayerX(int x) const {
	Vector2D<int> output(this->SIZE);

	for (int y = 0; y < this->SIZE; ++y) {
		std::vector<int> col = this->board[x][y].getPost();
		output[y] = this->fillPost(col);
	}

	return output;
}

Vector2D<int> GameBoard::getLayerY(int y) const {
	Vector2D<int> output(this->SIZE);

	for (int x = 0; x < this->SIZE; ++x) {
		std::vector<int> col = this->board[x][y].getPost();
		output[x] = this->fillPost(col);
	}

	return output;
}

Vector2D<int> GameBoard::getLayerZ(int z) const {
	Vector2D<int> output(this->SIZE);

	for (int x = 0; x < this->SIZE; ++x) {
		output[x] = std::vector<int>(this->SIZE);
		for (int y = 0; y < this->SIZE; ++y) {
			std::vector<int> col = this->board[x][y].getPost();
			output[x][y] = this->fillPost(col)[z];
		}
	}
	return output;
}

vector<vector<int> > GameBoard::getLayer(char c, int i) const {
	switch(c){
		case 'x':
			return getLayerX(i);
		case 'y':
			return getLayerY(i);
		case 'z':
			return getLayerZ(i);
		default:
			return {{-1}};
	}
	return {{-1}};
}

bool GameBoard::isFull() const {
	return numBalls == SIZE * SIZE * SIZE;
}

string drawBall(string skel, int index, int id){
	string replacement;
	string symbols = "OX";
	if(id){
		replacement = symbols[id - 1];
	} else {
		replacement = " ";
	}

	return skel.replace(index, 1, replacement);
}

void GameBoard::displayBoard() const {
	/*	
		string display = 
		"        *     *     *\n"
		"        *     *     *\n"
		"        * --- * --- *    0\n"  
		"    *  /  *  /  *  /\n"
		"    * /   * /   * /\n" 
		"    * --- * --- *    1\n"
		"*  /  *  /  *  /\n"
		"* /   * /   * /\n"
		"* --- * --- *    2 \n";
	 */
	string display = 
		"        *     *     *\n"
		"        *     *     *\n"
		"        * --- * --- *\n"  
		"    *  /  *  /  *  / \n"
		"    * /   * /   * /  \n" 
		"    * --- * --- *    \n"
		"*  /  *  /  *  /     \n"
		"* /   * /   * /      \n"
		"* --- * --- *        \n";

	vector<int> ball_indices;
	for(int i = 0; i < display.size(); i++){
		if(display[i] == '*'){
			ball_indices.push_back(i);
		}
	}

	vector<int> balls = flatten();

	for(int i = 0; i < 27; i++){
		display = drawBall(display, ball_indices[i], balls[i]);
	}

	//display += "0     1     2 X\\Y\n";

	cout << display << endl;
	return;
}

vector<int> GameBoard::flatten() const {
	vector<int> balls;

	for(int y = 0; y < 3; y++){
		for(int z = 2; z >= 0; z--){
			for(int x = 0; x < 3; x++){
				balls.push_back(getLayerY(y)[x][z]);
			}
		}
	}

	return balls;
}

vector<pair<int, int>> getAvailable(Vector2D<int> layer, std::function<bool(int)> condition) {
	vector<pair<int, int>> output;

	for (int i = 0; i < layer.size(); ++i) {
		for (int j = 0; j < layer[i].size(); ++j) {
			if (condition(layer[i][j])) {
				output.push_back(pair<int, int>(i, j));
			}
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

GameBoard GameBoard::operator=(const GameBoard &gb) {
	GameBoard newGameBoard = GameBoard(gb.SIZE);
	newGameBoard.board = gb.board;

	return newGameBoard;
}
