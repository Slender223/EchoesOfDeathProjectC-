#pragma once 
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

class Level2;
class MourningSky {
private:
	Text hitsStr;
	Font font;
	int hits = 0;
	Text time;
	Clock clickClock;
	Texture texture2;
	Texture texture3;
	Texture texture4;
	float timeRemaining = 0.0f;
	float timeLimit = 90.0f;
	bool hit = false;
	int dir = 0;
	bool isShot = false;
	double x1 = 0;
	double y1 = 0;
	bool movingLeft = false;
	bool isGameOver = false;
	bool hasWon = false;

public:
	struct Bird {
		float speed = 5.f;
		Texture texture;
		CircleShape bCircle;
	};



	MourningSky(RenderWindow& window, Texture& texture, Sprite& sprite);
	int PlayGame(RenderWindow& window, Texture& texture, Sprite& sprite);
	string timeConverter(float time);
	void BirdHit(bool goal, Bird& birdie, CircleShape& ball, RenderWindow& window, Sprite& sprite);
	friend class Level2;
};


