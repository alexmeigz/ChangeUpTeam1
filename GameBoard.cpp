#include "GameBoard.h"

GameBoard::GameBoard(const int size) : SIZE(size), board(size) {
    for (int i = 0; i < this->SIZE; ++i) {
        // set each element to a vector of size SIZE, passing in SIZE to the constructor of GoalPost
        this->board[i] = std::vector<GoalPost>(this->SIZE, this->SIZE);
    }
}

int GameBoard::removeBall(int x, int y) {
    if (x < 0 || x >= this->SIZE || y < 0 || y >= this->SIZE) {
        return false;
    }

    return this->board[x][y].pop();
}

bool GameBoard::addBall(int player, int x, int y) {
    if (x < 0 || x >= this->SIZE || y < 0 || y >= this->SIZE) {
        return false;
    }

    return this->board[x][y].push(player);
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

string drawBall(string skel, int index, int id){
	string replacement;
	if(id){
		replacement = to_string(id);
	} else {
		replacement = " ";
	}

	return skel.replace(index, 1, replacement);
}

void GameBoard::displayBoard() const {
	string display = 
		"        *     *     *\n"
		"        *     *     *\n"
		"        * --- * --- *\n"  
		"    *  /  *  /  *  /\n"
		"    * /   * /   * /\n" 
		"    * --- * --- *\n"
		"*  /  *  /  *  /\n"
		"* /   * /   * /\n"
		"* --- * --- *\n";

	vector<int> ball_indices;
	for(int i = 0; i < display.size(); i++){
		if(display[i] == '*'){
			ball_indices.push_back(i);
		}
	}

	vector<int> balls;
	//int balls[27];

	for(int y = 0; y < 3; y++){
		for(int z = 2; z >= 0; z--){
			for(int x = 0; x < 3; x++){
				balls.push_back(getLayerY(y)[x][z]);
			}
		}
	}

	for(int i = 0; i < 27; i++){
		display = drawBall(display, ball_indices[i], balls[i]);
	}

	cout << display << endl;
	return;
}
