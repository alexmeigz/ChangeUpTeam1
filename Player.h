#pragma once

class Player {
public:
    Player(int id, int maxBalls);
    void playerRemoveBall(); // player's ball was removed from board
    void playerAddBall(); // player put ball on board 
    //int playerViewBall() const;
    int ballsLeft() const; // I think this is more useful than playerViewBall()
    int playerGetId() const;
    int getScore() const;
    void setScore(int score);
private:
    const int PLAYER_ID;
    const int MAX_BALLS;
    int score;
    int playerBallCount; // number of balls on board
};