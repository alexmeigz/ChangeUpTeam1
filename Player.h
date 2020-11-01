#pragma once

class Player {
public:
    Player(int id);
    void playerRemoveBall();
    void playerAddBall();
    int playerViewBall() const;
    int playerGetId() const;
private:
    const int playerId;
    int playerBallCount;
};