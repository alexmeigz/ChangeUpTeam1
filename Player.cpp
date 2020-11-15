#include "Player.h"

#include <iostream>

//Pre-Condition: input is a string value for the team name
//Post-Condition: sets variable teamName to the input argument, sets playerBallCount to 16
Player::Player(int id, int maxBalls) : playerId(id), maxBalls(maxBalls) {
    playerBallCount = 16;
    score = 0;
}

//Pre-Condition: no input required
//Post-Condition:  decrease the value of variable playerBallCount by 1
void Player::playerRemoveBall(){
   playerBallCount--;
}

//Pre-Condition: no input required
//Post-Condition: increase the value of variable playerBallCount by 1
void  Player::playerAddBall(){
    playerBallCount++;
}

//Pre-Condition:  no input required
//Post-Condition:  returns the number of balls the player has left
int Player::ballsLeft() const{
    return playerBallCount;
}

//Pre-Condition: no input required
//Post-Condition:  returns the player id
int Player::playerGetId() const{
    return playerId;
}

//Pre-Condition: no input required
//Post-Condition:  returns player score
int Player::getScore() const{
    return score;
}

//Pre-Condition:  input: the player’s new score
//Post-Condition:  update the player’s score to the new score
void Player::setScore(int newScore){
    score = newScore;
}

void Player::addScore(int score) {
    this->score += score;
}
