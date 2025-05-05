#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/System.hpp>
#include <fstream>
#include <sstream>
#include <thread>
#include <cmath>
#include <chrono>
using namespace sf;
using namespace std;


class shadowStrikes {
private:
	Text goalsStr;
	Font font;
	int goals = 0;
	Text time;
	Clock clickClock;
	Texture texture2;
	bool scored = false;
	int dir = 0;
	bool isShot = false;
	double x1 = 0;
	double y1 = 0;
	bool movingLeft = false;
	bool stopped = true;
	bool isGameOver = false;
	float timeLimit = 90.0f;
	float timeRemaining = 0.0f;

public:
	bool hasWon = false;

	struct Goalie {
		float speed = 5.f;
		Texture texture;
		RectangleShape goalieBox;
	};

	

	shadowStrikes(RenderWindow& window, Texture& texture, Sprite& sprite);
	int PlayGame(RenderWindow& window, Texture& texture, Sprite& sprite);
	string timeConverter(float time);
	void GoalScored(bool goal, Goalie& goalie, CircleShape& ball, RenderWindow& window, Sprite& sprite);

};

