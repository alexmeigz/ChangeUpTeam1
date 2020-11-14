#include "Game.h"
#include <iostream>

const int SIZE = 3;
const int NUM_PLAYERS = 2;
const int MAX_BALL = 18;
const int WINNING_SCORE = 4;
const int MOVES_PER_TURN = 3;
const int MOVES_FIRST_TURN = 2;
const int REMOVES_PER_TURN = 1;


int main() {
    Game game(SIZE, 
              NUM_PLAYERS, 
              MAX_BALL, 
              WINNING_SCORE, 
              MOVES_PER_TURN, 
              MOVES_FIRST_TURN, 
              REMOVES_PER_TURN);
}