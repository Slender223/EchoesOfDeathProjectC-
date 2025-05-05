#include "Level1.h"
#include "Questions.h"
#include "shadowStrikes.h"
#include "Player.h"

Level1::Level1(sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite, sf::Text text, Player& playerRef) : player(playerRef) 
{
    string questionText1 = "Who moves unseen, slipping between light and shadow?";
    Questions question1(questionText1, { "Echo", " Sentinel", " Phantom", "Guardian" }, 0, false);
    questions.push_back(question1);

    string questionText2 = "Who silently shapes the fate of others, unseen but \npowerful?";
    Questions question2(questionText2, { "Whisperer", "Monarch", "Shadowbinder", "Watcher" }, 0, false);
    questions.push_back(question2);

    string questionText3 = "Who hides their true self, crafting an identity of \ndeception?";
    Questions question3(questionText3, { "Actor", "Illusionist", "Magician", "Impostor" }, 3, false);
    questions.push_back(question3);

    string questionText4 = "Who leaves no footprints yet changes everything they\n touch?";
    Questions question4(questionText4, { "Whisperer", "Reaper", "Rogue", "Shadow" }, 2, false);
    questions.push_back(question4);

    string questionText5 = "Does \"Twilight\" move unseen, in a place between darkness\n and light?";
    Questions question5(questionText5, { "True", "False" }, 0, true);
    questions.push_back(question5);

    string questionText6 = "Where do only the knowing find their way, a hidden path\n or door?";
    Questions question6(questionText6, { "Main Entrance", "Hidden Gate", "Open Road", "Secret Passage" }, 1, false);
    questions.push_back(question6);

    string questionText7 = "What place muffles sound, allowing unseen movement?";
    Questions question7(questionText7, { "Silent Hall", "Echo Chamber", "Whispering Forest", "Thunderous Cave" }, 0, false);
    questions.push_back(question7);

    string questionText8 = "What place holds no traces, yet its presence is felt?";
    Questions question8(questionText8, { "Forgotten Path", "Empty Room", "Haunted Mansion", "Desert" }, 0, false);
    questions.push_back(question8);

    string questionText9 = "Who guards the truth with silence, seen by none but\n known by few?";
    Questions question9(questionText9, { "Archivist", "Oracle", "Shade", "Watcher" }, 0, false);
    questions.push_back(question9);

    if (!font.loadFromFile("PixelifySans-Medium.ttf")) {
        cout << "Error loading font!" << endl;
        return;
    }

    //Riddle
    riddleDisplay.setFont(font);
    riddleDisplay.setCharacterSize(60);
    riddleDisplay.setFillColor(sf::Color::White);
    riddleDisplay.setPosition(250.f, 400.f);
    ifstream riddleFile("Textfiles/riddleGame.txt");
    if (riddleFile.is_open()) {
        stringstream buffer;
        buffer << riddleFile.rdbuf();
        riddleText = buffer.str();
        riddleFile.close();
    }
    else {
        riddleText = "Error: Could not load riddle.";
    }
    riddleDisplay.setString(riddleText);

    // Load the heart texture once before the loop
    if (!heartTexture.loadFromFile("Pics/heart.png")) {
        cout << "Error loading heart.png!" << endl;
        return;
    }
    hearts.clear();
    hearts.resize(player.getLives());
    int i = 0;
    for (auto itr = hearts.begin(); itr != hearts.end(); itr++, i++) {
        if (!displayPicture("heart.png", heartTexture, *itr))
            return;
        itr->setPosition(10 + i * 45, 15);
        itr->setScale(0.1f, 0.1f);
    }

    // Adjust timer box position
    timerBox.setSize(sf::Vector2f(210.f, 75.f));
    timerBox.setFillColor(sf::Color::Black);
    timerBox.setPosition(1390.0f, 40.0f);

    time.setFont(font);
    time.setCharacterSize(35);
    time.setFillColor(sf::Color::White);
    time.setPosition(1400.0f, 45.0f);

    // Adjust points box position
    pointsBox.setSize(sf::Vector2f(210.0f, 75.f));
    pointsBox.setFillColor(sf::Color::Black);
    pointsBox.setPosition(700.0f, 40.0f);

    points.setFont(font);
    points.setCharacterSize(35);
    points.setFillColor(sf::Color::White);
    points.setPosition(710.0f, 45.0f);
    //points.setString("Points: " + to_string(player.getPoints()));

    // Adjust anagram box position
    anagramBox.setSize(sf::Vector2f(600.f, 80.f));
    anagramBox.setFillColor(sf::Color::Black);
    anagramBox.setPosition(500.0f, 1300.0f);

    anagram.setFont(font);
    anagram.setCharacterSize(30);
    anagram.setFillColor(sf::Color::White);
    anagram.setPosition(715.0f, 1315.0f);

    // Initialize input box with fixed positions
    inputBox.setSize(sf::Vector2f(585.f, 140.f));
    inputBox.setFillColor(sf::Color::White);
    inputBox.setOutlineColor(sf::Color::Black);
    inputBox.setOutlineThickness(2.f);
    inputBox.setPosition(250.f, 500.f);  // Fixed position

    inputText.setFont(font);
    inputText.setCharacterSize(70);
    inputText.setFillColor(sf::Color::Black);
    inputText.setPosition(280.f, 520.f);  // Fixed position relative to input box

    inputStr = "";

    //hint
    passcodeHint.setFont(font);
    passcodeHint.setCharacterSize(30);
    passcodeHint.setFillColor(sf::Color::Green);
    passcodeHint.setPosition(400.f, 800.f);
    passcodeHint.setString("W___-____T");

    if (!lightBulbTexture.loadFromFile("pics/lightBulbIcon.png")) {
        cout << "Failed to load lightbulb image!" << endl;
    }
    lightBulb.setTexture(lightBulbTexture);
    lightBulb.setPosition(1400.0f, 1000.0f);
    lightBulb.setScale(0.2f, 0.2f);

    gameButton.setSize(sf::Vector2f(250.f, 80.f));
    gameButton.setFillColor(sf::Color::White);
    gameButton.setPosition(1300.f, 1500.f);

    gameButtonText.setFont(font);
    gameButtonText.setFillColor(sf::Color::Red);
    gameButtonText.setCharacterSize(50);
    gameButtonText.setString("try again");
    gameButtonText.setPosition(1310.f, 1510.f);


    // Load failed and rules textures
    if (!level1FailedTexture.loadFromFile("Pics/level1Failed.png")) {
        cout << "Error loading level1Failed.png!" << endl;
    }
    level1FailedSprite.setTexture(level1FailedTexture);
    level1FailedSprite.setPosition(0, 0);

    anagramStr = "";

    startButton.setSize(sf::Vector2f(400, 160));
    startButton.setFillColor(sf::Color::Black);
    startButton.setPosition(600, 980);
    startButtonText.setCharacterSize(80);
    startButtonText.setString("START");
    startButtonText.setPosition(670.f, 1005.f);
    startButtonText.setFont(font);
    startButtonText.setFillColor(sf::Color::White);


}

int Level1::play(sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite, sf::Text text) {
    bool startButtonClicked = false;
    bool riddleTime = true;
    bool quesPhase = false;
    bool passCodePhase = false;
    bool firstAttemptWrong = false;
    bool canType = false;
    float timeRemaining;
    int picNo = 1;
    int wrongAttempts = 0;
    multimap<sf::Text, sf::RectangleShape, TextComparator> buttons;
    bool gamePhase = false;
    int questionCount = 1;

    while (window.isOpen()) {
        sf::Event event;
        sf::Time elapsed = gameClock.getElapsedTime();
        float elapsedTime = elapsed.asSeconds();

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                    if (startButton.getGlobalBounds().contains(mousePos) && !startButtonClicked) {
                        startButtonClicked = true;
                        riddleTime = true;
                    }
                    else if (!riddleDisplay.getGlobalBounds().contains(mousePos) && riddleTime) {
                        riddleTime = false;
                        quesPhase = true;
                        gameClock.restart();
                        timeRemaining = 300;
                    }

                    if (lightBulb.getGlobalBounds().contains(mousePos) && !showHint) {
                        if (player.getPoints() >= 25) {  // Only allow hint if player has enough points
                            player - 25;    // Deduct 25 points
                            // Add this after deducting points
                            sf::Text deductionText("-25", font, 35);
                            deductionText.setFillColor(sf::Color::Red);
                            deductionText.setPosition(lightBulb.getPosition());
                            window.draw(deductionText);
                            window.display();
                            sf::sleep(sf::milliseconds(500));  // Show for half a second
                            int hintNumber = min(questionCount, static_cast<int>(questions.size()));
                            string hintImagePath = "Pics/question" + to_string(hintNumber) + "hint.png";
                            showHint = true;
                            if (hintTexture.loadFromFile(hintImagePath)) {
                                hintSprite.setTexture(hintTexture);
                                float scaleX = (window.getSize().x * 0.6f) / hintTexture.getSize().x;
                                float scaleY = (window.getSize().y * 0.6f) / hintTexture.getSize().y;
                                float scale = min(scaleX, scaleY);
                                hintSprite.setScale(scale, scale);
                                hintSprite.setPosition(
                                    (window.getSize().x - hintTexture.getSize().x * scale) / 2,
                                    (window.getSize().y - hintTexture.getSize().y * scale) / 2
                                );
                                
                            }
                            else {
                                cout << "Failed to load hint image: " << hintImagePath << endl;
                            }
                        }
                    }
                    else if (showHint && !hintSprite.getGlobalBounds().contains(mousePos)) {
                        showHint = false;
                    }
                    if (quesPhase) {
                        int i = 0;
                        for (sf::Text option : questions[questionCount - 1].optionsAsText()) {
                            if (option.getGlobalBounds().contains(mousePos)) {
                                bool isCorrect = (questions[questionCount - 1].correctAnswerIndex == i);
                                questions[questionCount - 1].optionColor[i] = ((isCorrect) ? sf::Color::Green : sf::Color::Red);
                                vector<sf::Sprite> sprites = { sprite, lightBulb };
                                sprites.insert(sprites.end(), hearts.begin(), hearts.end());
                                drawWindow(window, sprites, buttons, questions[questionCount - 1]);
                                sf::sleep(sf::milliseconds(500));
                                if (isCorrect) {
                                    if (!firstAttemptWrong) {
                                        player + 5;
                                    }
                                    anagramStr += option.getString()[0];
                                    questionCount++;
                                    firstAttemptWrong = false;
                                    wrongAttempts = 0;
                                }
                                else {
                                    wrongAttempts++;
                                    if (wrongAttempts >= 2)
                                        player.loseLife();
                                        
                                    firstAttemptWrong = true;
                                    questions[questionCount - 1].optionColor[i] = sf::Color::White;
                                }

                                break;
                            }
                            i++;
                        }
                    }
                    if (passCodePhase) 
                        if (inputBox.getGlobalBounds().contains(mousePos)) 
                            canType = true;

                    if(gamePhase)
                        if (gameButton.getGlobalBounds().contains(mousePos) && picNo == 1) {
                            picNo++;
                            gameButtonText.setString("     Play");
                        }
                        else if (gameButton.getGlobalBounds().contains(mousePos) && picNo == 2) {
                            shadowStrikes play(window, texture, sprite);
                            return play.PlayGame(window, texture, sprite);

                        }
                }
            }
        }

        hearts.resize(player.getLives());
        points.setString("Points: " + to_string(player.getPoints()));
        anagram.setString(anagramStr);
        timeRemaining = 300 - gameClock.getElapsedTime().asSeconds();
        time.setString(timeConverter(timeRemaining));
        if (hearts.empty()) {
            if (!displayPicture("gameover.png", texture, sprite))
                return -1;
            drawWindow(window, { sprite });
            sf::sleep(sf::seconds(2));
            return -1;
        }

        if (!startButtonClicked) {
            if (!displayPicture("level1.png", texture, sprite))
                return -1;
            drawWindow(window, { sprite }, startButton, startButtonText);
        }
        else if (riddleTime) {
            if (!displayPicture("lvl1.png", texture, sprite))
                return -1;
            drawWindow(window, { sprite }, riddleDisplay);
        }
        else {
            if (quesPhase) {
                timerStarted = true;
                if (questionCount >= 10) {
                    passCodePhase = true;
                    quesPhase = false;
                    continue;
                }
                
                buttons = { {time, timerBox}, {points, pointsBox}, {anagram, anagramBox} };
                vector<sf::Sprite> sprites = { sprite, lightBulb };
                sprites.insert(sprites.end(), hearts.begin(), hearts.end());
                if (showHint) {
                    vector<sf::Sprite> sprites = { sprite, hintSprite };
                    sprites.insert(sprites.end(), hearts.begin(), hearts.end());
                    drawWindow(window, sprites, buttons);
                }
                else {
                    drawWindow(window, sprites, buttons, questions[questionCount - 1]);
                }
                
            }
            else if (passCodePhase) {
                if (!displayPicture("passcode.png", texture, sprite))
                    return -1;
                if (canType && event.type == sf::Event::TextEntered) {
                    if (event.text.unicode == '\b' && !inputStr.empty())
                        inputStr.pop_back();
                    else if (event.text.unicode < 128 && event.text.unicode != '\r')
                        inputStr += static_cast<char>(event.text.unicode);
                    inputText.setString(inputStr);
                }
                if (canType && Keyboard::isKeyPressed(Keyboard::Enter)) {
                    if (inputStr == "WIRE-SHAFT") {
                        player + 80;
                        points.setString("Points: " + to_string(player.getPoints()));
                        if (!texture.loadFromFile("Pics/Congratulations.png")) {
                            cerr << "ERROR FINDING PIC" << endl;
                            return -1;
                        }
                        sprite.setTexture(texture);
                        sprite.setPosition(0, 0);
                        window.draw(sprite);
                        window.display();
                        sf::sleep(sf::seconds(2));
                        return 0;
                    }
                    else {
                        passCodePhase = false;
                        gamePhase = true;
                    }
                }
                buttons.insert({ inputText, inputBox });
                vector<sf::Sprite> sprites = { sprite };
                sprites.insert(sprites.end(), hearts.begin(), hearts.end());
                drawWindow(window, sprites, buttons);
                buttons.erase(inputText);
            } 
            else if (gamePhase) {
                if (!displayPicture(to_string(picNo) + ".png", texture, sprite))
                    return -1;
                drawWindow(window, { sprite }, gameButton, gameButtonText);
            }
        }
    }
    return 0;
}


bool Level1::displayPicture(string picName, sf::Texture& texture, sf::Sprite& sprite) {
    if (!texture.loadFromFile("Pics/" + picName)) {
        cerr << "Error loading " + picName + " from Pics!!" << endl;
        return false;
    }
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
    return true;
}

string Level1::timeConverter(float time)
{
    string t = "Time | ";
    int minutes = (int)time / 60;
    int seconds = (int)time % 60;
    // Format with leading zeros
    t += (minutes < 10 ? "0" : "") + to_string(minutes) + ":" +
        (seconds < 10 ? "0" : "") + to_string(seconds);
    return t;
}


void Level1::drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites) {
    window.clear(sf::Color::Black);
    for (sf::Sprite sp : sprites)
        window.draw(sp);

    window.display();
}

void Level1::drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites, multimap<sf::Text, sf::RectangleShape, TextComparator> buttons) {
    window.clear(sf::Color::Black);
    for (sf::Sprite sp : sprites)
        window.draw(sp);

    for (auto m : buttons) {
        window.draw(m.second);
        window.draw(m.first);
    }

    window.display();
}

void Level1::drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites, multimap<sf::Text, sf::RectangleShape, TextComparator> buttons , Questions question) {
    window.clear(sf::Color::Black);
    for (sf::Sprite sp : sprites)
        window.draw(sp);

    for (auto m : buttons) {
        window.draw(m.second);
        window.draw(m.first);
    }

    window.draw(question.questionAsText());
    for (sf::Text option : question.optionsAsText()) {
        window.draw(option);
    }
    window.display();
}

void Level1::drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites, sf::RectangleShape button, sf::Text text)
{
    window.clear(sf::Color::Black);
    for (sf::Sprite sp : sprites)
        window.draw(sp);
    window.draw(button);
    window.draw(text);
    window.display();
}

void Level1::drawWindow(sf::RenderWindow& window, sf::Sprite sprite, sf::Text text) {
    window.clear(sf::Color::Black);
    window.draw(sprite);
    window.draw(text);
    window.display();
}

void Level1::drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites, Questions question) {
    window.clear(sf::Color::Black);
    for (sf::Sprite sp : sprites)
        window.draw(sp);
    window.draw(question.questionAsText());
    for (sf::Text option : question.optionsAsText()) {
        window.draw(option);
    }
    window.display();
}
