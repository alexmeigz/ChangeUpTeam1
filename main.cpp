#include <iostream>
#include "GameBoard.h"
#include <vector>

int main() {
    int size = 5;

    GameBoard gb(size);

    Vector2D<int> layer = gb.getLayerX(1);

    for (int i = 0; i < size; ++i) {
        std::cout << layer[1][i] << std::endl;
    }
}
