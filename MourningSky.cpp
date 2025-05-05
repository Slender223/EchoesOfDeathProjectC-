#include "MourningSky.h"
#include "MiniGames.h" 

MourningSky::MourningSky(RenderWindow& window, Texture& texture, Sprite& sprite)
{
	//Initialize the font
	if (!font.loadFromFile("arial.ttf")) {
		cout << "Error loading font!" << endl;
		return;
	}

	hitsStr.setFont(font);
	hitsStr.setCharacterSize(50);
	hitsStr.setFillColor(sf::Color::White);
	hitsStr.setPosition(100.0f, 100.0f);
	hitsStr.setString("Hits: 00");


	time.setFont(font);
	time.setCharacterSize(50);
	time.setFillColor(sf::Color::White);
	time.setPosition(1300.0f, 100.0f);
	time.setString("Time: 0:00");
}

int MourningSky::PlayGame(RenderWindow& window, Texture& texture, Sprite& sprite)
{
	//Loading the background the game 
	if (!texture.loadFromFile("Pics/sunnyField.png")) {
		cerr << "ERROR FINDING PIC" << endl;
		return -1;
	}
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);

	//Initialize Bird 
	Bird birdie;
	birdie.bCircle.setRadius(50.f);
	if (!texture2.loadFromFile("Pics/bird.png")) {
		cerr << "ERROR FINDING birdie" << endl;
		return -1;
	}
	birdie.bCircle.setTexture(&texture2);
	birdie.bCircle.setPosition(150.f, 200.f);

	//Initialize rock 
	CircleShape rock;
	rock.setRadius(20.f);
	if (!texture3.loadFromFile("Pics/rock.png")) {
		cerr << "Error loading the rock" << endl;
		return -1;
	}
	rock.setTexture(&texture3);
	rock.setPosition(Vector2f(820.0f, 1340.0f));

	// Initialize sling 
	RectangleShape sling;
	sling.setSize(Vector2f(150.0f, 150.0f));
	if (!texture4.loadFromFile("Pics/sling.png")) {
		cerr << "ERROR FINDING sling" << endl;
		return -1;
	}
	sling.setTexture(&texture4);
	sling.setPosition(800.f, 1400.f);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (!isGameOver) {

			//Update the time
			Time elapsed = clickClock.getElapsedTime();

			if (!isGameOver) {
				timeRemaining = timeLimit - elapsed.asSeconds();

				if (timeRemaining <= 0.0f) {
					isGameOver = true;
					timeRemaining = 0.0f;
					hasWon = false;
				}
			}
			time.setString(timeConverter(elapsed.asSeconds()));

			if (hits >= 3) {
				hasWon = true;
				isGameOver = true;
				return 0;
			}


			//update birdie 
			MoveTarget<CircleShape>(10, 1580, &birdie.bCircle, movingLeft, dir, birdie.speed);

			//update rock 

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				x1 = mousePos.x;
				y1 = mousePos.y;
				isShot = true;

			}

			ProjectileMov<CircleShape>(x1, y1, &rock, isShot);


			//Check for hits

			hit = checkCollision<CircleShape, CircleShape>(&rock, &birdie.bCircle);

			if (hit) {
				BirdHit(hit, birdie, rock, window, sprite);
			}
			else if (!hit && (rock.getPosition().y <= y1 && (rock.getPosition().x <= x1 || rock.getPosition().x >= x1))) {
				BirdHit(hit, birdie, rock, window, sprite);
			}
			else if (rock.getPosition().y <= 0 || (rock.getPosition().x <= 0 || rock.getPosition().y >= 1600)) {
				BirdHit(hit, birdie, rock, window, sprite);
			}




			//Draw 
			window.clear(Color::White);
			window.draw(sprite);
			window.draw(birdie.bCircle);
			window.draw(rock);
			window.draw(sling);
			window.draw(hitsStr);
			//window.draw(timerBox);
			window.draw(time);
			window.display();
		}
	}
	return 0;
}

string MourningSky::timeConverter(float time)
{
	string t = "Time | ";
	int minutes = (int)time / 60;
	int seconds = (int)time % 60;
	t += to_string(minutes) + " : " + to_string(seconds);
	return t;

}

void MourningSky::BirdHit(bool hit, Bird& birdie, CircleShape& rock, RenderWindow& window, Sprite& sprite)
{
	if (hit) {
		isShot = false;
		rock.setPosition(Vector2f(820.0f, 1340.0));

		//increase birdie speed 
		birdie.speed += 5;

		//add the hits
		hits++;
		hitsStr.setString("Hits: " + to_string(hits));
		Text hitText;
		hitText.setFont(font);
		hitText.setCharacterSize(50);
		hitText.setFillColor(sf::Color::White);
		hitText.setPosition(800.0f, 800.0f);
		hitText.setString("HIT!!!");
		window.clear(Color::White);
		window.draw(sprite);
		window.draw(rock);
		window.draw(birdie.bCircle);
		window.draw(hitText);
		window.draw(hitsStr);
		window.draw(time);
		window.display();
		sf::sleep(sf::milliseconds(500));



	}
	else if (!hit) {
		isShot = false;
		rock.setPosition(Vector2f(820.0f, 1340.0f));
	}

}


