#include "GameBoard.h"

#include <iostream>
GameBoard::GameBoard(const int size) : SIZE(size), board(size) {
    for (int i = 0; i < this->SIZE; ++i) {
        // set each element to a vector of size SIZE, passing in SIZE to the constructor of GoalPost
        this->board[i] = std::vector<GoalPost>(this->SIZE, this->SIZE);
    }
}

bool GameBoard::removeBall(int x, int y) {
    return this->board[x][y].pop();
}

bool GameBoard::addBall(int player, int x, int y) {
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
        for (int y = 0; y < this->SIZE; ++y) {
            std::vector<int> col = this->board[x][y].getPost();
            output[x][y] = this->fillPost(col)[z];
        }
    }

    return output;
}
