#include "GameBoard.h"
#include "utilities.h"

GameBoard::GameBoard(int size) : SIZE(size) {
    this->board = new GoalPost ** [size];
    for (int i = 0; i < size; ++i) {
        this->board[i] = new GoalPost * [size];

        for (int j = 0; j < size; ++j) {
            this->board[i][j] = new GoalPost(size);
        }
    }
}

int GameBoard::removeBall(int x, int y) {
    return this->board[x][y]->pop();
}

bool GameBoard::addBall(int player, int x, int y) {
    return this->board[x][y]->push(player);
}

int ** GameBoard::getLayerX(int x) const {
    int ** output = create2D(this->SIZE);

    for (int y = 0; y < this->SIZE; ++y) {
        int * col = this->board[x][y]->getPost();
        for (int z = 0; z < this->SIZE; ++z) {
            output[y][z] = col[z];
        }
        delete col;
    }

    return output;
}

int ** GameBoard::getLayerY(int y) const {
    int ** output = create2D(this->SIZE);

    for (int x = 0; x < this->SIZE; ++x) {
        int * col = this->board[x][y]->getPost();
        for (int z = 0; z < this->SIZE; ++z) {
            output[x][z] = col[z];
        }
        delete col;
    }

    return output;
}

int ** GameBoard::getLayerZ(int z) const {
    int ** output = create2D(this->SIZE);

    for (int x = 0; x < this->SIZE; ++x) {
        for (int y = 0; y < this->SIZE; ++y) {
            int * col = this->board[x][y]->getPost();
            output[x][y] = col[z];
            delete col;
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
