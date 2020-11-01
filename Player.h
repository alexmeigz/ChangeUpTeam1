#pragma once

class Player {
public:
    Player(int id, int maxBalls);
    void playerRemoveBall();
    void playerAddBall();
    int playerViewBall() const;
    int hasBallsLeft() const;
    int playerGetId() const;
private:
    const int playerId;
    const int maxBalls;
    int playerBallCount;
};