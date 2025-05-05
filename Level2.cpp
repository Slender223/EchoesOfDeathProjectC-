#include "Level2.h"
#include "Avatar.h"
#include "Questions.h"
#include "MourningSky.h"

Level2::Level2(sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite, sf::Text& text, Player& playerRef) : player(playerRef) {
    if (!font.loadFromFile("PixelifySans-Regular.ttf")) {
        cout << "Error loading font!" << endl;
        return;
    }

    text.setFont(font);
    //E1
    string qText1 = "Who is the most likely suspect behind the murder \nof the player's parents, considering their involvement\n in exposing the Black Ember Syndicate?";
    Questions q1(qText1, { "Ember Viper", " Shadow Talon", " Void Chimera" }, 1, false);
    questions.push_back(q1);

    string qText2 = "Why might Shadow Talon be responsible for the murder of \nthe player's parents?";
    Questions q2(qText2, { "To protect the syndicate's secrets", "To eliminate personal enemies", "To maintain power within the syndicate" }, 1, true);
    questions.push_back(q2);
    //E2
    string qText3 = "Who was most likely responsible for Reaper& Viper's deaths?";
    Questions q3(qText3, { "Marcus Crowley", "Rouge faction within the Syndicate", "Betrayer within their team", "Elias Markov and his men" }, 4, true);
    questions.push_back(q3);

    string qText4 = "What was the primary reason someone might have \ntargeted Reaper & Viper?";
    Questions q4(qText4, { "Their connection to Crowley and his criminal empire" , "They uncovered a hidden faction within the government", "Repercussions from a previous mission against\n Elias Markov's family", "\nThey were getting too close to uncovering a traitor within their own ranks" }, 3, true);
    questions.push_back(q4);

    string qText5 = "What event triggered the suspicion of foul play\n in Reaper & Viper's deaths?";
    Questions q5(qText5, { "A warning message from an unknown source", "The unexpected explosion that almost killed them", "The sudden betrayal from a trusted ally", "The fact that no one was able to track their last known location" }, 2, true);
    questions.push_back(q5);
    //E3
    string qText6 = "Which factor might link the murder of the player's parents\n to the operation on the cipher, considering the potential \ninternal corruption within the agency?";
    Questions q6(qText6, { "Internal Mole", "Sleeper Agents Activation", "Agency's Leadership" }, 1, false);
    questions.push_back(q6);

    string qText7 = "The cipher, which was left unfinished by the parents,\n could hold the key to revealing not only sleeper agents \nbut also the identity of the mole within \nthe agency, potentially linked to the murder.";
    Questions q7(qText7, { "True", "False" }, 1, false);
    questions.push_back(q7);

    string qText8 = "Which of the following groups might have the strongest \nmotive to orchestrate the murder of the player's parents,\n based on their involvement in Operation: Cipher's End ?";
    Questions q8(qText8, { "Foreign Enemies" , "Agency Leadership", "Cryptographers" }, 2, false);
    questions.push_back(q8);
    //E4
    string qText9 = "Dr.Emil Rausch may be responsible for the death of the \nplayer's parents.";
    Questions q9(qText9, { "True", "False" }, 1, false);
    questions.push_back(q9);

    string qText10 = "The player's parents discovered the list of names after \ninvestigating Dr.Rausch's experiments.";
    Questions q10(qText10, { "True", "False" }, 1, false);
    questions.push_back(q10);

    string qText11 = "The list of names included only Dr.Rausch's victims.";
    Questions q11(qText11, { "True", "False" }, 2, false);
    questions.push_back(q11);

    string qText12 = "Someone within the agency was leaking information\n to Dr.Rausch.";
    Questions q12(qText12, { "True", "False" }, 1, false);
    questions.push_back(q12);

    string qText13 = "Why did Dr.Rausch target the player's parents ?";
    Questions q13(qText13, { "They were involved in shutting down his \nexperiments years ago", "\nThey were working as undercover agents for\n another organization" ,"\nThey had stolen his research", "They were trying to expose the agency's corruption" }, 1, true);
    questions.push_back(q13);

    string qText14 = "What was Dr.Rausch planning to do with the\n player's parents?";
    Questions q14(qText14, { "Take revenge for his earlier defeat","Use them as pawns in his new experiment", "Force them to work for him as agents", "Expose them as traitors to the agency" }, 2, true);
    questions.push_back(q14);

    //E5
    string qText15 = "How might the player's parents' involvement in eliminating\n the target during Operation: Ghost Thorn\n be connected to their murder?";
    Questions q15(qText15, { "Diplomatic Fallout", "Revenge from the Wraith's Associates", "Internal Agency Betrayal" }, 1, false);
    questions.push_back(q15);

    string qText16 = "The Wraith's associates, after the assassination plot was\n stopped, may have been motivated to kill the player's\n parents to protect their network and ensure that no \nmore information about their operations was revealed?";
    Questions q16(qText16, { "\nTrue", "False" }, 1, false);
    questions.push_back(q16);

    string qText17 = "Which of the following is the most likely motive for the parents'\n murder, given their involvement in Operation: Ghost Thorn?";
    Questions q17(qText17, { "To Keep the Truth Hidden", "Revenge by Political Rivals", "Disagreement with the Agency" }, 1, false);
    questions.push_back(q17);

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

    timeLimit = 600.0f; // 10 minutes in seconds
    timeRemaining = timeLimit;
    timerStarted = false;

    if (!lightBulbTexture.loadFromFile("pics/lightBulbIcon.png")) {
        cout << "Failed to load lightbulb image!" << endl;
    }
    lightBulb.setTexture(lightBulbTexture);
    lightBulb.setPosition(1400.0f, 1000.0f);
    lightBulb.setScale(0.2f, 0.2f);
}

int Level2::play(sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite, sf::Text& text) {
    points.setString("Points: " + to_string(player.getPoints()));
    sf::RectangleShape startButton(sf::Vector2f(400, 160));
    startButton.setFillColor(sf::Color::Black);
    startButton.setPosition(600, 980);
    text.setCharacterSize(80);
    text.setFillColor(sf::Color::White);
    text.setPosition(670.f, 1005.f);
    bool buttonClicked = false;
    int index = 0;
    float timePassed = 0.0f;
    sf::Texture avTexture;
    sf::Sprite avSprite;
    sf::Texture dTexture;
    sf::Sprite dSprite;
    Avatar avatar(avTexture, avSprite);
    sf::RectangleShape proceedButton(sf::Vector2f(240.0f, 100.0f));
    proceedButton.setFillColor(sf::Color::Blue);
    proceedButton.setPosition(1280.0f, 1350.0f);
    //bool showCongrats = false;
    bool entryOpen = false;
    int entryNo = 1;
    bool quesPhase = false;
    int questionCount = 1;
    bool hasClicked = false;
    int wrongAttempts = 0;
    bool firstAttemptWrong = false;
    float timeRemaining = timeLimit;
    bool isGameOver = false;
    bool mouseClicked = false;
    bool firstEntryStarted = false;
    //bool playerWonMourningSky = (playMourningSky(window, texture, sprite) == 1);

    while (window.isOpen()) {
        sf::Event event;
        mouseClicked = false;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    //sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    mouseClicked = true;
                    if (startButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                        buttonClicked = true;
                        level2Clock.restart();
                    }
                    if (proceedButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                        entryOpen = false;
                        quesPhase = true;
                    }
                    for (int i = 0; i < questions[questionCount - 1].options.size(); i++) {
                        if (questions[questionCount - 1].optionsAsText()[i].getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                            questions[questionCount - 1].optionColor[i] = ((questions[questionCount - 1].correctAnswerIndex == i + 1) ? sf::Color::Green : sf::Color::Red);
                            drawWindow(window, { sprite, avSprite }, questions[questionCount - 1]);
                            sf::sleep(sf::milliseconds(500));
                            bool isCorrect = (questions[questionCount - 1].correctAnswerIndex == i + 1);
                            if (isCorrect) {
                                if (!firstAttemptWrong) {
                                    player.setPoints(player.getPoints() + 10);
                                    points.setString("Points: " + to_string(player.getPoints()));
                                }
                                wrongAttempts = 0;
                                firstAttemptWrong = false;
                                questionCount++;
                            }
                            else {
                                wrongAttempts++;
                                firstAttemptWrong = true;

                                if (wrongAttempts >= 2) {
                                    if (!hearts.empty()) {
                                        hearts.pop_back();
                                    }
                                    wrongAttempts = 0;
                                }
                            }

                            questions[questionCount - 1].optionColor[i] = sf::Color::White;


                            if (quesNo[entryNo - 1] < questionCount) {
                                quesPhase = false;
                                entryNo++;
                            }
                            break;
                        }
                    }
                    
                    /*if (hearts.empty()) {
                        if (!displayPicture("gameover.png", texture, sprite))
                            return -1;
                        drawWindow(window, sprite);
                        sf::sleep(sf::milliseconds(2000));
                        return -1;
                    }*/
                }
            }
        }
        sf::Time timer = level2Clock.getElapsedTime();
        if (!buttonClicked) {
            if (!displayPicture("lvl2Intro.png", texture, sprite))
                return -1;
            text.setString("START");
            time.setString("Time | 10:00");
            drawWindow(window, { sprite }, startButton, text);
        }
        else if (buttonClicked && timer.asSeconds() < 45) {
           if (!displayPicture("lvl2Stranger.png", texture, sprite))
               return -1;
          string str = "    Your parents were more than just\n  teachers, they were spies, masters \n   of deception who handled secrets,    \n              capable of toppling nations. \n                They left a diary, records of   \n                       everything they knew.....";
            text.setCharacterSize(45);
            text.setPosition(620.0f, 275.0f);
           text.setFillColor(sf::Color::Black);
           if (timer.asSeconds() > timePassed) {
               typeWritter(str, text, index);
                timePassed = timer.asSeconds() + 0.02f;
           }
            drawWindow(window, sprite, text);

        }
        else if (timer.asSeconds() <= 32) {
           text.setString("");
           index = 0;
           timePassed = 32.0f;
        }
        else if (timer.asSeconds() <= 60) {
           //Read between the lines.And when the time comes… be ready.
          string str = "   They had names, location, and \n  classified information. Now, it's in \n    your hands. Guard it with your life.\n                If it falls into the wrong hands\n                  you'll be their next target.\n                       Trust no one!!";
           if (timer.asSeconds() > timePassed) {
               typeWritter(str, text, index);
               timePassed = timer.asSeconds() + 0.08f;
           }
           drawWindow(window, sprite, text);
        }
        else if (timer.asSeconds() <= 80){
            if (!displayPicture("hs.png", texture, sprite))
                return -1;
            if (!font.loadFromFile("PixelifySans-regular.ttf")) {
                cout << "Error loading font!" << endl;
                return -1;
            }
            fstream file("TextFiles/Instructions.txt");
            stringstream buffer;
            buffer << file.rdbuf();
            string textContent = buffer.str();
            text.setPosition(300.0f, 280.0f);
            //text.setCharacterSize(40);
            text.setFillColor(sf::Color::Color(255, 69, 0));
            text.setString(textContent);

            drawWindow(window, sprite, text);
        }
        else {
            if (entryOpen) {
                text.setPosition(1300.5f, 1365.0f);
                text.setCharacterSize(45);
                text.setFillColor(sf::Color::Black);
                text.setString("Proceed");
                drawWindow(window, { sprite, avSprite , dSprite }, proceedButton, text);
            }
            else if (quesPhase) {
                drawWindow(window, { sprite, avSprite }, questions[questionCount - 1]);

                //drawWindow(window, { sprite, avSprite });

            }
            else {
                sf::Vector2f currentPos = avSprite.getPosition();

                if (Keyboard::isKeyPressed(Keyboard::Right)) {
                    avatar.LoadAvatar(avSprite, 'D');
                    
                }
                if (Keyboard::isKeyPressed(Keyboard::Left)) {
                    
                    avatar.LoadAvatar(avSprite, 'A');
                }
                if (Keyboard::isKeyPressed(Keyboard::Up)) {
                    /*if (currentPos.y > 340.0f) {
                        avatar.LoadAvatar(avSprite, 'W');
                    }*/
                    avatar.LoadAvatar(avSprite, 'W');
                }
                if (Keyboard::isKeyPressed(Keyboard::Down)) {
                    /*if (currentPos.y < 780.0f) {
                        avatar.LoadAvatar(avSprite, 'S');
                    }*/
                    avatar.LoadAvatar(avSprite, 'S');
                }
                //drawWindow(window, { sprite, avSprite });
                if (Keyboard::isKeyPressed(Keyboard::Enter)) {
                    cout << avSprite.getPosition().x << " : " << avSprite.getPosition().y << endl;
                    if (avSprite.getPosition().x >= 365 && avSprite.getPosition().x <= 900 && avSprite.getPosition().y >= 960 && avSprite.getPosition().y <= 1100) {
                        if (entryNo == 1) {
                            entryOpen = true;
                            if (!dTexture.loadFromFile("Pics/entry1.png")) {
                                cout << "Error finding entry" << endl;
                                return -1;
                            }
                            dSprite.setTexture(dTexture);
                            //dSprite.setScale(0.5f, 0.65f);
                            dSprite.setPosition(350.0f, 205.0f);
                        }
                        else {
                            //Insert CODE1
                        }
                    }
                    else if (avSprite.getPosition().x >= 505 && avSprite.getPosition().x <= 730 && avSprite.getPosition().y >= 820 && avSprite.getPosition().y <= 895) {
                        if (entryNo == 2) {
                            entryOpen = true;
                            if (!dTexture.loadFromFile("Pics/entry2.png")) {
                                cout << "Error finding entry" << endl;
                                return -1;
                            }
                            dSprite.setTexture(dTexture);
                            /*dSprite.setScale(0.5f, 0.5f);
                            dSprite.setPosition(150.0f, 85.0f);*/
                        }
                        else {
                            //Insert CODE1
                        }
                    }
                    else if (avSprite.getPosition().x >= 445 && avSprite.getPosition().x <= 800 && avSprite.getPosition().y >= 675 && avSprite.getPosition().y <= 750) {
                        if (entryNo == 3) {
                            entryOpen = true;
                            if (!dTexture.loadFromFile("Pics/entry3.png")) {
                                cout << "Error finding entry" << endl;
                                return -1;
                            }
                            dSprite.setTexture(dTexture);
                            //dSprite.setScale(0.5f, 0.5f);
                            //dSprite.setPosition(150.0f, 85.0f);
                        }
                        else {
                            //Insert CODE1
                        }
                    }
                    else if (avSprite.getPosition().x >= 560 && avSprite.getPosition().x <= 690 && avSprite.getPosition().y >= 570 && avSprite.getPosition().y <= 640) {
                        if (entryNo == 4) {
                            entryOpen = true;
                            if (!dTexture.loadFromFile("Pics/entry4.png")) {
                                cout << "Error finding entry" << endl;
                                return -1;
                            }
                            dSprite.setTexture(dTexture);
                            //dSprite.setScale(0.5f, 0.5f);
                            //dSprite.setPosition(150.0f, 85.0f);
                        }
                        else {
                            //Insert CODE1
                        }
                    }
                    else if (avSprite.getPosition().x >= 515 && avSprite.getPosition().x <= 715 && avSprite.getPosition().y >= 490 && avSprite.getPosition().y <= 550) {
                        if (entryNo == 5) {
                            entryOpen = true;
                            if (!dTexture.loadFromFile("Pics/entry5.png")) {
                                cout << "Error finding entry" << endl;
                                return -1;
                            }
                            dSprite.setTexture(dTexture);

                        }
                        else {
                            //Insert CODE1
                        }
                    }
                    else {
                        //Insert CODE1
                    }

                }
                drawWindow(window, { sprite, avSprite });
            }
        }
        if (entryOpen)
            firstEntryStarted = true;

        if (!timerStarted && questionCount <= questions.size() && firstEntryStarted) {
            questionClock.restart();
            timerStarted = true;
            timeRemaining = timeLimit; // Reset the countdown
        }

        if (!isGameOver && timerStarted) {
            timeRemaining = timeLimit - questionClock.getElapsedTime().asSeconds();

            if (timeRemaining <= 0) {
                isGameOver = true;
                timeRemaining = 0; // Freeze time at 0
            }
            time.setString(timeConverter(timeRemaining));
        }
        if (hearts.empty() && !isGameOver) {
            isGameOver = true;
            timeRemaining = timeLimit - questionClock.getElapsedTime().asSeconds();
            time.setString(timeConverter(timeRemaining));
        }

        if (isGameOver) {
            displayPicture("gameover.png", texture, sprite);
            drawGameOverWindow(window, sprite);
            sf::sleep(sf::milliseconds(2000));
            return -1;
        }
        else if (questionCount >= 17) {
            if (!displayPicture("level2Congrats.png", texture, sprite))
                return -1;
            drawCongratsWindow(window, sprite);
            sf::sleep(sf::milliseconds(5000));
            return 0;


        }
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

        if (mouseClicked && quesPhase && lightBulb.getGlobalBounds().contains(worldPos)) {
            if (player.getPoints() >= 50) {
                player.setPoints(player.getPoints() - 50);
                points.setString("Points: " + to_string(player.getPoints()));

                // Show -25 deduction
                sf::Text deductionText("-50", font, 24);
                deductionText.setFillColor(sf::Color::Red);
                deductionText.setPosition(lightBulb.getPosition());
                window.draw(deductionText);
                window.display();
                sf::sleep(sf::milliseconds(500));

                string hintImagePath;
                string entryImagePath;
                if (!entryOpen) {
                    entryImagePath = "Pics/Entry" + to_string(entryNo) + "Hints/";
                    if (quesPhase) {
                        // Show hint for the current question
                        //int hintNumber = min(questionCount, static_cast<int>(questions.size()));
                        hintImagePath = entryImagePath + to_string(questionCount) + "Hint.png";
                    }
                }

                if (hintTexture.loadFromFile(hintImagePath)) {
                    hintSprite.setTexture(hintTexture);
                    float scaleX = (window.getSize().x * 0.6f) / hintTexture.getSize().x;
                    float scaleY = (window.getSize().y * 0.6f) / hintTexture.getSize().y;
                    float scale = min(scaleX, scaleY);
                    hintSprite.setScale(scale, scale);
                    hintSprite.setPosition(350.0f, 405.0f);
                    showHint = true;
                }
                else {
                    cout << "Failed to load hint image: " << hintImagePath << endl;
                }
            }
            else {
                // instructions
                sf::Texture instructionTexture;
                sf::Sprite instructionSprite;
                if (!instructionTexture.loadFromFile("Pics/gameHint.png")) {
                    cout << "Error loading insufficient points image!" << endl;
                }
                text.setCharacterSize(50);
                text.setFillColor(sf::Color::Red);
                text.setPosition(230.0f, 1500.0f);
                text.setString("Click anywhere to continue");
                instructionSprite.setTexture(instructionTexture);
                instructionSprite.setPosition(0, 0);

                bool waitingForClick = true;
                while (waitingForClick && window.isOpen()) {
                    sf::Event event;
                    while (window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed)
                            window.close();
                        else if (event.type == sf::Event::MouseButtonPressed)
                            waitingForClick = false;
                    }

                    window.clear(sf::Color::White);
                    window.draw(instructionSprite);
                    window.draw(text);
                    window.display();
                }
                sf::Texture instructionTexture2;
                sf::Sprite instructionSprite2;
                if (!instructionTexture2.loadFromFile("Pics/morningSkyInstruction.png")) {
                    cout << "Error loading second instruction image!" << endl;
                }

                instructionSprite2.setTexture(instructionTexture2);
                instructionSprite2.setPosition(0, 0);

                bool waitingForSecondClick = true;
                while (waitingForSecondClick && window.isOpen()) {
                    sf::Event event;
                    while (window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed)
                            window.close();
                        else if (event.type == sf::Event::MouseButtonPressed)
                            waitingForSecondClick = false;
                    }

                    window.clear(sf::Color::White);
                    window.draw(instructionSprite2);
                    window.draw(text);
                    window.display();
                }

                sf::Texture gameTexture;
                sf::Sprite gameSprite;
                MourningSky mourningSky(window, gameTexture, gameSprite);
                mourningSky.PlayGame(window, gameTexture, gameSprite);
                bool playerWon = false; // Set based on your actual mini-game result
                if (mourningSky.hits == 3) {
                    playerWon = true;
                }
                if (playerWon) {
                    string entryImagePath = "Pics/Entry" + to_string(entryNo) + "Hints/";
                    string hintImagePath = entryImagePath + to_string(questionCount) + "Hint.png";

                    if (hintTexture.loadFromFile(hintImagePath)) {
                        hintSprite.setTexture(hintTexture);
                        float scaleX = (window.getSize().x * 0.6f) / hintTexture.getSize().x;
                        float scaleY = (window.getSize().y * 0.6f) / hintTexture.getSize().y;
                        float scale = min(scaleX, scaleY);
                        hintSprite.setScale(scale, scale);
                        hintSprite.setPosition(350.0f, 405.0f);
                        showHint = true;
                    }
                    else {
                        cout << "Failed to load hint after mini-game: " << hintImagePath << endl;
                    }
                }
                else {
                    cout << "You lost MourningSky! No hint awarded." << endl;
                }
            }
        }
        if (showHint) {
            window.draw(sprite);
            window.draw(hintSprite);
            window.display();
            sf::sleep(sf::milliseconds(5000));  // display hint for 5 seconds
            showHint = false;
        }

    }


    return 0;
}


void Level2::typeWritter(string textInfo, sf::Text& text, int& index)
{
    if (index < textInfo.size()) {
        string printedString = "";
        for (int i = 0; i < index; i++)
            printedString += textInfo[i];
        text.setString(printedString);
        index++;
    }
}

string Level2::timeConverter(float time)
{
    string t = "Time | ";
    int minutes = (int)time / 60;
    int seconds = (int)time % 60;
    t += to_string(minutes) + " : " + to_string(seconds);
    return t;
}

bool Level2::displayPicture(string picName, sf::Texture& texture, sf::Sprite& sprite) {
    if (!texture.loadFromFile("Pics/" + picName))
    {
        cerr << "Error loading " + picName + " from Pics!!" << endl;
        return false;
    }
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
    //sprite.setScale(0.8f, 0.8f);
    return true;
}

void Level2::drawWindow(sf::RenderWindow& window, sf::Sprite sprite) {
    window.clear(sf::Color::Black);
    window.draw(sprite);
    window.display();
    for (sf::Sprite heart : hearts) {
        window.draw(heart);
    }
    window.draw(pointsBox);
    window.draw(points);
    window.draw(timerBox);
    window.draw(time);
    window.display();
}

void Level2::drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites) {
    window.clear(sf::Color::Black);
    for (sf::Sprite sp : sprites)
        window.draw(sp);
    for (sf::Sprite heart : hearts) {
        window.draw(heart);
    }
    window.draw(pointsBox);
    window.draw(points);
    window.draw(timerBox);
    window.draw(time);
    window.display();
}

void Level2::drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites, sf::RectangleShape button, sf::Text text) {
    window.clear(sf::Color::Black);
    for (sf::Sprite sp : sprites)
        window.draw(sp);
    window.draw(button);
    window.draw(text);
    window.display();
}

void Level2::drawWindow(sf::RenderWindow& window, sf::Sprite sprite, sf::Text text) {
    window.clear(sf::Color::Black);
    window.draw(sprite);
    window.draw(text);
    window.display();
}

void Level2::drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites, Questions question) {
    window.clear(sf::Color::Black);
    for (sf::Sprite sp : sprites)
        window.draw(sp);
    window.draw(question.questionAsText());
    for (sf::Text option : question.optionsAsText()) {
        window.draw(option);
    }
    for (sf::Sprite heart : hearts) {
        window.draw(heart);
    }
    window.draw(pointsBox);
    window.draw(points);
    window.draw(timerBox);
    window.draw(time);
    window.draw(lightBulb);
    window.display();
}

void Level2::drawGameOverWindow(sf::RenderWindow& window, sf::Sprite& sprite) {
    window.clear(sf::Color::Black);
    window.draw(sprite);
    window.display();
}

void Level2::drawCongratsWindow(sf::RenderWindow& window, sf::Sprite& sprite) {
    window.clear(sf::Color::Black);
    window.draw(sprite);
    window.display();
}