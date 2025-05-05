#pragma once
#include <SFML/Graphics.hpp>
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/System.hpp>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>

using namespace std;
using namespace sf;

class Avatar {
private:
	int xPos[6] = { 0, 400, 800, 1200, 800, 400 };
	int index = 0;
	sf::Texture texture;

public:
	Avatar(sf::Texture& texture, sf::Sprite& sprite);
	void LoadAvatar(sf::Sprite& sprite, char dir);


};