#pragma once
#include <string>

struct Move {
	std::string add_rem;
	int x;
	int y;
	bool operator==(const Move& other) const {
		return (add_rem == other.add_rem) &&
			(x == other.x) && (y == other.y);
	}
};

class Player {
	public:
		//Pre-Condition: input is a string value for the team name
		//Post-Condition: sets variable teamName to the input argument, sets playerBallCount to 16
		Player(int id, int maxBalls);

		/*
		   Player(const Player &og): playerId(og.playerId),
		   maxBalls(og.maxBalls) {
		   playerBallCount = og.playerBallCount;
		   score = og.score;
		   }
		 */

		//Pre-Condition: no input required
		//Post-Condition:  decrease the value of variable playerBallCount by 1
		void playerRemoveBall();

		//Pre-Condition: no input required
		//Post-Condition: increase the value of variable playerBallCount by 1
		void  playerAddBall();

		//Pre-Condition:  no input required
		//Post-Condition:  returns the number of balls the player has left
		int ballsLeft() const;

		//Pre-Condition: no input required
		//Post-Condition:  returns the player id
		int playerGetId() const;

		//Pre-Condition: no input required
		//Post-Condition:  returns player score
		int getScore() const;

		//Pre-Condition:  input: the player’s new score
		//Post-Condition:  update the player’s score to the new score
		void setScore(int score);

		void addScore(int score);

		Player operator=(const Player &p){
			Player newPlayer = Player(p.playerId, p.maxBalls);
			newPlayer.playerBallCount = p.playerBallCount;
			newPlayer.score = p.score;
			return newPlayer;
		}

	private:
		//integer variable to keep explicit title of each player
		const int playerId;

		//integer variable to keep track of how many balls each individual player has
		int playerBallCount;

		int score;

		const int maxBalls;	
};
