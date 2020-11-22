#pragma once
#include "Game.h"
#include "Bot.h"

const int SIZE = 3;
const int NUM_PLAYERS = 2;
const int MAX_BALL = 16;
const int WINNING_SCORE = 4;
const int MOVES_PER_TURN = 3;
const int MOVES_FIRST_TURN = 2;
const int REMOVES_PER_TURN = 1;

class State {
	public:
		State () {
			g = new Game(SIZE, 
					NUM_PLAYERS, 
					MAX_BALL, 
					WINNING_SCORE, 
					MOVES_PER_TURN, 
					MOVES_FIRST_TURN, 
					REMOVES_PER_TURN);
		}



		~State() {
			delete g;
		}

	private:
		Game * g;
		Bot bot1 = Bot("bot 1");
		Bot bot2 = Bot("bot 2");
};
