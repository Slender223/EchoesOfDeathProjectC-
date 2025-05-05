#include "Intro.h"

Intro::Intro(sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite) {

    phaseTimes[0] = 0;
    for (int i = 1; i < 12; i++)
        phaseTimes[i] = phaseTimes[i - 1] + durations[i - 1];

    if (!font.loadFromFile("PixelifySans-Medium.ttf")) {
        cout << "Error loading font!" << endl;
        return;
    }
    text.setFont(font);
    text.setCharacterSize(70);
    text.setFillColor(sf::Color::White);
    text.setPosition(280, 400);
}

int Intro::StartIntro(sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite) {
    gameClock.restart();
    float timePassed = 2.0f;
    bool introFinished = false;

    while (window.isOpen()) {
        sf::Event event;
        
        sf::Time elapsed = gameClock.getElapsedTime();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));;
                    if (playButton.getGlobalBounds().contains(mousePos)) {
                    }
                }
            }
        }

        if (elapsed.asSeconds() <= phaseTimes[1]) {
            if (!displayPicture("house.png", texture, sprite))
                return -1;
            drawWindow(window, sprite);
        }
        else if (elapsed.asSeconds() <= phaseTimes[2]) {
            if (gameClock.getElapsedTime().asSeconds() > timePassed) {
                typeWritter("intro.txt", text, index);
                timePassed += 0.10f;
            }
            drawWindow(window, sprite, text);
        }
        else if (gameClock.getElapsedTime().asSeconds() <= phaseTimes[3]) {
            if (!displayPicture("letter1.png", texture, sprite))
                return -1;
            index = 0;
            printedString = "";
            drawWindow(window, sprite);
            timePassed = phaseTimes[3];

        }
        else if (gameClock.getElapsedTime().asSeconds() <= phaseTimes[4]) {
            if (gameClock.getElapsedTime().asSeconds() > timePassed) {
                typeWritter("intro2.txt", text, index);
                timePassed += 0.10f;
            }
            drawWindow(window, sprite, text);

        }
        else if (gameClock.getElapsedTime().asSeconds() <= phaseTimes[5]) {
            index = 0;
            printedString = "";
            timePassed = phaseTimes[5];
            drawWindow(window, sprite);

        }
        else if (gameClock.getElapsedTime().asSeconds() <= phaseTimes[6]) {
            if (gameClock.getElapsedTime().asSeconds() > timePassed) {
                typeWritter("intro3.txt", text, index);
                timePassed += 0.10f;
            }
            drawWindow(window, sprite, text);

        }
        else if (gameClock.getElapsedTime().asSeconds() <= phaseTimes[7]) {
            if (!displayPicture("letter.png", texture, sprite))
                return -1;
            index = 0;
            printedString = "";
            timePassed = phaseTimes[7];
            drawWindow(window, sprite);

        }
        else if (gameClock.getElapsedTime().asSeconds() <= phaseTimes[8]) {
            if (gameClock.getElapsedTime().asSeconds() > timePassed) {
                typeWritter("riddle.txt", text, index);
                timePassed += 0.15f;
            }
            drawWindow(window, sprite, text);

        }
        else if (gameClock.getElapsedTime().asSeconds() <= phaseTimes[9]) {
            if (!displayPicture("letter.png", texture, sprite))
                return -1;
            index = 0;
            printedString = "";
            timePassed = phaseTimes[9];
            drawWindow(window, sprite);
        }
        else if (gameClock.getElapsedTime().asSeconds() <= phaseTimes[10]) {
            if (gameClock.getElapsedTime().asSeconds() > timePassed) {
                typeWritter("riddle2.txt", text, index);
                timePassed += 0.15f;
            }
            drawWindow(window, sprite, text);

        }
        else {
            break;
        }
    }
    return 0;
}

bool Intro::displayPicture(string picName, sf::Texture& texture, sf::Sprite& sprite) {
    if (!texture.loadFromFile("Pics/" + picName))
    {
        cerr << "Error loading " + picName + " from Pics!!" << endl;
        return false;
    }
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
    return true;
}

void Intro::typeWritter(string textFile, sf::Text& text, int& index) {
    fstream file("TextFiles/" + textFile);
    stringstream buffer;
    buffer << file.rdbuf();
    string textContent = buffer.str();

    if (index < textContent.size()) {
        printedString = "";
        for (int i = 0; i < index; i++)
            printedString += textContent[i];
        text.setString(printedString);
        index++;
    }
}



void Intro::drawWindow(sf::RenderWindow& window, sf::Sprite sprite) {
    window.clear(sf::Color::Black);
    window.draw(sprite);
    window.display();
}

void Intro::drawWindow(sf::RenderWindow& window, sf::Sprite sprite, sf::Text text) {
    window.clear(sf::Color::Black);
    window.draw(sprite);
    window.draw(text);
    window.display();
}