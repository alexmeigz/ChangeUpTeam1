class Player {
	public:
		//Pre-Condition: input is a string value for the team name
		//Post-Condition: sets variable teamName to the input argument, sets playerBallCount to 16
		Player(int id, int maxBalls);

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

	private:
		//integer variable to keep explicit title of each player
		const int playerId;
		
		//integer variable to keep track of how many balls each individual player has
		int playerBallCount;
		
		int score;

		const int maxBalls;	
};
