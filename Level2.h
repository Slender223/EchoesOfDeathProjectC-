#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/System.hpp>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
#include "Questions.h"
#include "Player.h"

using namespace std;

class Level2 {
private:
	sf::Font font;
	sf::Clock level2Clock;
	vector<Questions>  questions;
	const int quesNo[5] = { 2,5, 8, 14, 17 };
	sf::Clock clickClock;
	sf::RectangleShape timerBox;
	sf::Text time;
	sf::RectangleShape pointsBox;
	sf::Text points;
	vector<sf::Sprite> hearts;
	sf::Texture heartTexture;
	Player& player;
	vector<int>::iterator itr;
	sf::Clock gameClock;
	sf::Clock questionClock;
	bool gameStarted = false;
	float timeLimit;
	float timeRemaining;
	bool timerStarted;
	sf::Texture lightBulbTexture;
	sf::Sprite lightBulb;
	sf::Texture hintTexture;
	sf::Sprite hintSprite;
	bool showHint = false;

public:
	Level2(sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite, sf::Text& text, Player& player);
	int play(sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite, sf::Text& text);
	void typeWritter(string textInfo, sf::Text& text, int& index);
	bool displayPicture(string picName, sf::Texture& texture, sf::Sprite& sprite);
	void drawWindow(sf::RenderWindow& window, sf::Sprite sprite);
	void drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites);
	void drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites, sf::RectangleShape button, sf::Text text);
	void drawWindow(sf::RenderWindow& window, sf::Sprite sprite, sf::Text text);
	void drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites, Questions question);
	void drawGameOverWindow(sf::RenderWindow& window, sf::Sprite& sprite);
	void drawCongratsWindow(sf::RenderWindow& window, sf::Sprite& sprite);

	string timeConverter(float time);
};