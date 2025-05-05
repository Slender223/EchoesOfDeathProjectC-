#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/System.hpp>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
#include "Questions.h"
#include "Avatar.h"
#include "Player.h"

class Level3 {
private:
	sf::Text text;
	sf::Font font;
	sf::Clock clickClock;
	vector<Questions>  questions;
	const int quesInRoom[6] = { 1, 21, 36, 46, 55, 65 };
	const int autoInRoom[5] = { 3, 4, 3, 4, 5 };
	sf::RectangleShape timerBox;
	sf::Text time;
	sf::Clock questionClock;
	float timeLimit;
	float timeRemaining;
	bool timerStarted;
	sf::RectangleShape pointsBox;
	sf::Text points;
	vector<sf::Sprite> hearts;
	sf::Texture heartTexture;
	Player& player;
	vector<int>::iterator itr;
	string instructionText;
	sf::Text instructioDisplay;

public:
	Level3(sf::RenderWindow& window, sf::Sprite& sprite, sf::Texture& texture, Player& player);
	int start(sf::RenderWindow& window, sf::Sprite& sprite, sf::Texture& texture);
	bool displayPicture(string picName, sf::Texture& texture, sf::Sprite& sprite);
	void drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites);
	void drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites, sf::Text text);
	void drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites, sf::RectangleShape button, sf::Text text);
	void drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites, Questions question);
	void drawWindow(sf::RenderWindow& window, sf::Sprite sprite, sf::Text text);
	void drawGameOverWindow(sf::RenderWindow& window, sf::Sprite& sprite);
	string timeConverter(float time);
};