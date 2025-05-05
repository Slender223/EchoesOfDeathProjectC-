//#include <SFML/Audio.hpp>
//#include <iostream>
//
//int main() {
//	// Load a music file
//	sf::Music music;
//	if (!music.openFromFile("04-CocoSA-Rise-Up-Ft-Nev-(JustNaija.com).wav")) {
//		std::cerr << "Error: Could not load music file!" << std::endl;
//		return -1;
//	}
//
//	// Play the music
//	music.play();
//
//	std::cout << "Press Enter to stop the music..." << std::endl;
//	std::cin.get();  // Wait for user input before exiting
//
//	return 0;
//}


#include "GameLoader.h"

GameLoader::GameLoader(sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite, sf::Text& text) {
    if (!font.loadFromFile("PixelifySans-Medium.ttf")) {
        cout << "Error loading font!" << endl;
        return;
    }
    text.setFont(font);  // Use class member font
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setString("");
    text.setPosition(700, 1300);

    // Create the Start Button
    startButton.setSize(sf::Vector2f(185.f, 100.f));
    startButton.setFillColor(sf::Color::Black);
    startButton.setPosition(750.f, 750.f);
}


int GameLoader::Load(sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite, sf::Text& text) {
    float timePassed = 2.0f;
    int index = 0;
    while (window.isOpen()) {
        sf::Event event;
        sf::Time elapsed = gameClock.getElapsedTime();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (startButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                        return 0;
                }
            }
        }

        if (elapsed.asSeconds() <= 2.0f) {
            if (!displayPicture("coverPicture.png", texture, sprite))
                return -1;
            drawWindow(window, sprite);
        }
        else if (elapsed.asSeconds() <= 12.0f) {
            if (gameClock.getElapsedTime().asSeconds() > timePassed) {
                typeWritter("Loading....", text, index);
                timePassed = elapsed.asSeconds() + 0.15f;
            }
            drawWindow(window, sprite, text);
        }
        else {
            // Set text for the Start Button
            text.setString("START");
            text.setFillColor(sf::Color::White);

            // Center the text inside the button
            sf::FloatRect textBounds = text.getLocalBounds();
            sf::Vector2f buttonPos = startButton.getPosition();
            sf::Vector2f buttonSize = startButton.getSize();

            text.setPosition(770, 770);

            drawWindow(window, sprite, startButton, text);
        }
    }
    return 0;
}


bool GameLoader::displayPicture(string picName, sf::Texture& texture, sf::Sprite& sprite) {
    if (!texture.loadFromFile("Pics/" + picName))
    {
        cerr << "Error loading " + picName + " from Pics!!" << endl;
        return false;
    }
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
    return true;
}

void GameLoader::typeWritter(string textInfo, sf::Text& text, int& index) {
    if (index < textInfo.size()) {
        string printedString = "";
        for (int i = 0; i < index; i++)
            printedString += textInfo[i];
        text.setString(printedString);
        index++;
    }
}


void GameLoader::drawWindow(sf::RenderWindow& window, sf::Sprite sprite) {
    window.clear(sf::Color::Black);
    window.draw(sprite);
    window.display();
}

void GameLoader::drawWindow(sf::RenderWindow& window, sf::Sprite sprite, sf::Text text) {
    window.clear(sf::Color::Black);
    window.draw(sprite);
    window.draw(text);
    window.display();
}

void GameLoader::drawWindow(sf::RenderWindow& window, sf::Sprite sprite, sf::RectangleShape button, sf::Text buttonText) {
    window.clear(sf::Color::Black);
    window.draw(sprite);
    window.draw(button);
    window.draw(buttonText);
    window.display();
}