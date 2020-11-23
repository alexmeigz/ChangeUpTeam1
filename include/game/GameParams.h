#pragma once

#include "utility.h"
#include <vector>
#include <utility>

const int SIZE = 3;
const int NUM_PLAYERS = 2;
const int MAX_BALL = 18;
const int WINNING_SCORE = 4;
const int MOVES_PER_TURN = 3;
const int MOVES_FIRST_TURN = 2;
const int REMOVES_PER_TURN = 1;

const vector<pair<int, int>> ORDERED_PAIRS = crossing(SIZE, SIZE); // all combinations (0,0) to (2, 2)
const vector<triple> ORDERED_TRIPLES = crossing(SIZE, SIZE, SIZE); // all combinations (0, 0, 0) to (2, 2, 2)