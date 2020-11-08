#include "GameBoard.h"
#include "utilities.h"

GameBoard::GameBoard(const int size) : SIZE(size) {
    init2D<GoalPost>(this->board, this->SIZE);
}

bool GameBoard::removeBall(int x, int y) {
    return this->board[x][y].pop();
}

bool GameBoard::addBall(int player, int x, int y) {
    return this->board[x][y].push(player);
}

std::vector<int> GameBoard::fillPost(std::vector<int> post) const {
    std::vector<int> output = post;
    
    // probably a better way to do idk
    while(output.size() != this->SIZE) {
        output.push_back(0);
    }

    return output;
}

Vector2D<int> GameBoard::getLayerX(int x) const {
    Vector2D<int> output = init2D<int>(this->SIZE);

    for (int y = 0; y < this->SIZE; ++y) {
        std::vector<int> col = this->board[x][y].getPost();
        output[y] = this->fillPost(col);
    }

    return output;
}

Vector2D<int> GameBoard::getLayerY(int y) const {
    Vector2D<int> output = init2D<int>(this->SIZE);

    for (int x = 0; x < this->SIZE; ++x) {
        std::vector<int> col = this->board[x][y].getPost();
        output[x] = this->fillPost(col);
    }

    return output;
}

Vector2D<int> GameBoard::getLayerZ(int z) const {
    Vector2D<int> output = init2D<int>(this->SIZE);

    for (int x = 0; x < this->SIZE; ++x) {
        for (int y = 0; y < this->SIZE; ++y) {
            std::vector<int> col = this->board[x][y].getPost();
            output[x][y] = col.size() > z ? col[z] : 0;
        }
    }

    return output;
}
