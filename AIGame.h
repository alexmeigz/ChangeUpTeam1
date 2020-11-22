#pragma once
#include "Game.h"
#include <random>
#include <string>

#include <vector>
#include <utility>

class AIGame : public Game {
public:
    AIGame(int playerId, int size, int numPlayers, int maxBall, int winningScore, int movesPerTurn, int movesFirstTurn, int removesPerTurn)
     : Game(size, numPlayers, maxBall, winningScore, movesPerTurn, movesFirstTurn, removesPerTurn), PLAYER_ID(playerId) {}

    bool makeMove(std::string move, int x, int y);

private:
    void AIMakeMove();

    const int PLAYER_ID;
};