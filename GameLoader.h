#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/System.hpp>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>

using namespace std;

class GameLoader {
private:

	sf::Clock gameClock;
	sf::Font font;
	sf::RectangleShape startButton;
	sf::RectangleShape instructionsButton;
	sf::RectangleShape aboutButton;

public:
	GameLoader(sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite, sf::Text& text);
	int Load(sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite, sf::Text& text);
	bool displayPicture(string picName, sf::Texture& texture, sf::Sprite& sprite);
	void typeWritter(string textInfo, sf::Text& text, int& index);
	void drawWindow(sf::RenderWindow& window, sf::Sprite sprite);
	void drawWindow(sf::RenderWindow& window, sf::Sprite sprite, sf::Text text);
	void drawWindow(sf::RenderWindow& window, sf::Sprite sprite, sf::RectangleShape button, sf::Text buttonText);
};