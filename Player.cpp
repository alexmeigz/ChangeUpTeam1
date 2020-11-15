#include "Player.h"

#include <iostream>

//Pre-Condition: input is a string value for the team name
//Post-Condition: sets variable teamName to the input argument, sets playerBallCount to 16
Player::Player(int id, int maxBalls) : playerId(id), maxBalls(maxBalls) {
    playerBallCount = 0;
    score = 0;
}

//Pre-Condition: no input required
//Post-Condition:  decrease the value of variable playerBallCount by 1
void Player::playerRemoveBall(){
    --this->playerBallCount;
}

//Pre-Condition: no input required
//Post-Condition: increase the value of variable playerBallCount by 1
void  Player::playerAddBall(){
    ++this->playerBallCount;
}

//Pre-Condition:  no input required
//Post-Condition:  returns the number of balls the player has left
int Player::ballsLeft() const{
    return this->maxBalls - this->playerBallCount;
}

//Pre-Condition: no input required
//Post-Condition:  returns the player id
int Player::playerGetId() const{
    return this->playerId;
}

//Pre-Condition: no input required
//Post-Condition:  returns player score
int Player::getScore() const{
    return this->score;
}

//Pre-Condition:  input: the player’s new score
//Post-Condition:  update the player’s score to the new score
void Player::setScore(int score){
    this->score = score;
}
