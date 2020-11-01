#include "GameBoard.h"

int ** create2D (int size) {
    int ** output = new int * [size];
    for (int i = 0; i < size; ++i) {
        output[i] = new int [size];
    }    
    return output;
}

GameBoard::GameBoard(int size) : SIZE(size) {
    this->board = new GoalPost ** [size];
    for (int i = 0; i < size; ++i) {
        this->board[i] = new GoalPost * [size];

        for (int j = 0; j < size; ++j) {
            this->board[i][j] = new GoalPost(size);
        }
    }
}

int GameBoard::removeBall(X x, Y y) {
    return this->board[(int)x][(int)y]->pop();
}

bool GameBoard::addBall(int player, X x, Y y) {
    return this->board[(int)x][(int)y]->push(player);
}

int ** GameBoard::getLayer(X x) const {
    int ** output = create2D(this->SIZE);

    for (int y = 0; y < this->SIZE; ++y) {
        std::vector<int> col = this->board[(int)x][y]->getPost();
        for (int z = 0; z < this->SIZE; ++z) {
            output[y][z] = col[z];
        }
    }

    return output;
}

int ** GameBoard::getLayer(Y y) const {
    int ** output = create2D(this->SIZE);

    for (int x = 0; x < this->SIZE; ++x) {
        std::vector<int> col = this->board[x][(int)y]->getPost();
        for (int z = 0; z < this->SIZE; ++z) {
            output[x][z] = col[z];
        }
    }

    return output;
}

int ** GameBoard::getLayer(Z z) const {
    int ** output = create2D(this->SIZE);

    for (int x = 0; x < this->SIZE; ++x) {
        for (int y = 0; y < this->SIZE; ++y) {
            output[x][y] = this->board[x][y]->getPost()[(int)z];
        }
    }

    return output;
}

GameBoard::~GameBoard() {
    for (int i = 0; i < this->SIZE; ++i) {
        for (int j = 0; j < this->SIZE; ++j) {
            delete this->board[i][j];
        }
        delete this->board[i];
    }
    delete this->board;
}
