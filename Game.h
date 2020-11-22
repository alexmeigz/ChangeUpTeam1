#pragma once

#include <string>
#include <vector>
#include <utility>
#include <unordered_map>

#include "Dict.h"
#include "GameBoard.h"
#include "Player.h"

using namespace std;

class Game {
	public:
		Game(int size, int numPlayers, int maxBall, int winningScore, int movesPerTurn, int movesFirstTurn, int removesPerTurn);
		// Pre-Condition: Game parameters	
		//post-condition: initializes game with desired gameboard size, max number of balls per player, the winning score,
		// moves a player can make per turn, moves a player can make the first turn, max number of removes a player can make in a turn and initializes the two players and gameboard

		void displayBoard() const;
		//Pre-condition: 
		//Post-condition: prints board

		bool makeMove(string move, int x, int y);
		//Pre-Condition: input for move is either ADD or REMOVE , x and y are coordinates
		//Post-Condition: returns 1 for success and 0 for failure to make move

		bool finished() const;
		//Pre-Condition: no input required
		//Post-Condition:  1 if the game is finished and 0 if it’s not

		int winner() const;

		int whoseTurn() const;
		//Pre-Condition:  no input required
		//Post-Condition:  returns the id of the player who has to make a move

		bool canRemove() const;
		//Pre-Condition:  no input required
		//Post-Condition:  returns true if the current player has a remove move available

		int movesRemaining() const;
		//Pre-Condition:  no input required
		//Post-Condition:  returns the number of moves the current player has on the turn

		int getScore(int player) const;
		//Pre-Condition: player id
		//Post-Condition:  player’s score

		int ballsLeft() const;
		//Pre-Condition:  no input required
		//Post-Condition:  returns the number of balls the current player has remaining

		vector<pair<int, int>> availableAdds() const;
		vector<pair<int, int>> availableRemoves() const;
		vector<int> flatten() const;

		//Game(const Game &og);

		Game operator=(const Game &g);

		vector<int> get_state_after(Move move);
		Dict<Move, vector<int> > get_possibilities();
	private:
		GameBoard gameboard; //gameboard structure 
		std::vector<Player> player_arr;
		bool turnTracker; //true = player 1’s turn; false = player 2’s turn
		int turn;
		int moves;
		int removes;
		const int MAX_BALL;
		const int WINNING_SCORE;
		const int MOVES_PER_TURN;
		const int MOVES_FIRST_TURN;
		const int REMOVES_PER_TURN;
		const int NUM_PLAYERS;
		const int SIZE;

		vector<int> layerDiagScore(char c, int i);
		void set3dDiagScore();
		void set2dDiagScore();
		void setZScore();
		void setYScore();
		void setXScore();

		int maxMoves() const;
		//precondition: n/a
		//postcondition: returns the number of max moves;

		void setScores();
		//Pre-Condition:  no input required
		//Post-Condition:  calculates scores for each player

		int tryMove(std::string move, int x, int y);
		//Pre-Condition: the type of move (add/remove) and position on board
		//Post-Condition:  returns true if the move was successful  
};
