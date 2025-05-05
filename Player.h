#pragma once
#include <iostream>

class Player {
private:
    int lives;
    int points;

public:
    Player() : lives(5), points(50) {}
    Player(int l, int p) : lives(l), points(p) {}

    //Operator overloads
    void operator+(int p) { points += p; }
    void operator-(int p) { points -= p; }
    void loseLife() { if (lives > 0) lives--; }

    int getPoints() const { return points; }
    int getLives() const { return lives; }

    void setPoints(int p) { points = p; }
    void setLives(int l) { lives = l; }
};