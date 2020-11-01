#include <iostream>

#include "Game.h"

int main() {
    Game game(3, 16);
    game.makeMove(Move::ADD, X::LEFT, Y::BACK);
}