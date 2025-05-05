#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/System.hpp>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>

using namespace std;

class Intro {
private:
    sf::Text text;
    sf::Font font;
    sf::Clock gameClock;
    sf::RectangleShape playButton;
    string printedString = "";
    int index = 0;
    float durations[12] = {
        2.0f, 20.0f, 2.0f, 24.0f, 2.0f, 24.0f, 2.0f, 24.0f, 2.0f, 26.0f, 2.0f, 30.0f
    };
    float phaseTimes[12]; // Store cumulative phase start times
    sf::RectangleShape rectangle; // Width: 200, Height: 100

public:
    Intro(sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite);
    int StartIntro(sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite);
    bool displayPicture(string picName, sf::Texture& texture, sf::Sprite& sprite);
    void typeWritter(string textFile, sf::Text& text, int& index);
    void drawWindow(sf::RenderWindow& window, sf::Sprite sprite);
    void drawWindow(sf::RenderWindow& window, sf::Sprite sprite, sf::Text text);
};