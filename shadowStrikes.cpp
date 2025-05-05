#include "shadowStrikes.h"
#include "MiniGames.h"

shadowStrikes::shadowStrikes(RenderWindow& window, Texture& texture, Sprite& sprite)
{
	//Initialize the font
	if (!font.loadFromFile("arial.ttf")) {
		cout << "Error loading font!" << endl;
		return;
	}

	goalsStr.setFont(font);
	goalsStr.setCharacterSize(50);
	goalsStr.setFillColor(sf::Color::White);
	goalsStr.setPosition(100.0f, 200.0f);
	goalsStr.setString("Goals: 00");

	time.setFont(font);
	time.setCharacterSize(50);
	time.setFillColor(sf::Color::White);
	time.setPosition(1300.0f, 200.0f);
	time.setString("Time: 0:00");
}


int shadowStrikes::PlayGame(RenderWindow& window, Texture& texture, Sprite& sprite)
{
	//Loading the background the game 
	if (!texture.loadFromFile("Pics/field.png")) {
		cerr << "ERROR FINDING PIC" << endl;
		return -1;
	}
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);

	//Initailize goalie 
	Goalie goalie;
	goalie.goalieBox.setSize(Vector2f(200.0f, 250.0f));
	if (!goalie.texture.loadFromFile("Pics/goalie.png")) {
		cerr << "ERROR FINDING Goalie" << endl;
		return -1;
	}
	goalie.goalieBox.setTexture(&goalie.texture);
	goalie.goalieBox.setPosition(320.f, 600.f);


	//Create the ball
	CircleShape ball;
	ball.setRadius(50.f);
	if (!texture2.loadFromFile("Pics/ball.png")) {
		cerr << "Error loading the ball" << endl;
		return -1;
	}
	ball.setTexture(&texture2);
	ball.setPosition(Vector2f(840.0f, 1320.0f));



	while (window.isOpen()) {
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

				if (timeRemaining <= 0) {
					isGameOver = true;
					timeRemaining = 0;
					hasWon = false;
				}

			}
			time.setString(timeConverter(timeRemaining));

			if (goals >= 3) {
				hasWon = true;
				isGameOver = true;
			}
			//update goalie 
			MoveTarget<RectangleShape>(320, 1280, &goalie.goalieBox, movingLeft, dir, goalie.speed);

			
			//update ball  
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				x1 = mousePos.x;
				y1 = mousePos.y;
				isShot = true;

			}

			ProjectileMov<CircleShape>(x1, y1, &ball, isShot);

			stopped = checkCollision<CircleShape, RectangleShape>(&ball, &goalie.goalieBox);

			//Collision ball
			if (x1 > 300 && x1 < 1366 && y1 > 406 && y1 < 856) {
				if (stopped) {
					scored = false;
					GoalScored(scored, goalie, ball, window, sprite);
				}
				else if (!stopped && (ball.getPosition().y <= y1 && (ball.getPosition().x <= x1 || ball.getPosition().x >= x1))) {
					scored = true;
					GoalScored(scored, goalie, ball, window, sprite);
				}
			}
			else if (stopped) {
				scored = false;
				GoalScored(scored, goalie, ball, window, sprite);

			}
			else if (ball.getPosition().y <= 0 || (ball.getPosition().x <= 0 || ball.getPosition().x >= 1600)) {
				scored = false;
				GoalScored(scored, goalie, ball, window, sprite);

			}

			//Draw 
			window.clear(Color::White);
			window.draw(sprite);
			window.draw(ball);
			window.draw(goalie.goalieBox);
			//window.draw(GoalsBox);
			window.draw(goalsStr);
			//window.draw(timerBox);
			window.draw(time);
			window.display();
		}
		else if (hasWon && isGameOver) {
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
			if (!texture.loadFromFile("Pics/gameover.png")) {
				cerr << "ERROR FINDING PIC" << endl;
				return -1;
			}
			sprite.setTexture(texture);
			sprite.setPosition(0, 0);
			window.draw(sprite);
			window.display();
			sf::sleep(sf::seconds(2));
			return -1;
		}

	}

	return 0;
}

string shadowStrikes::timeConverter(float time)
{
	string t = "Time | ";
	int minutes = (int)time / 60;
	int seconds = (int)time % 60;
	t += to_string(minutes) + " : " + to_string(seconds);
	return t;
}

void shadowStrikes::GoalScored(bool goal, Goalie& goalie, CircleShape& ball, RenderWindow& window, Sprite& sprite)
{

	if (scored) {
		isShot = false;
		ball.setPosition(Vector2f(840.0f, 1320.0f));
		//increase goalie speed 
		goalie.speed += 5;
		//add the goals
		goals++;
		goalsStr.setString("Goals: " + to_string(goals));
		Text scoredText;
		scoredText.setFont(font);
		scoredText.setCharacterSize(100);
		scoredText.setFillColor(sf::Color::Green);
		scoredText.setPosition(800.0f, 800.0f);
		scoredText.setString("GOAL!!!");
		window.clear(Color::White);
		window.draw(sprite);
		window.draw(ball);
		window.draw(goalie.goalieBox);
		window.draw(scoredText);
		//window.draw(GoalsBox);
		window.draw(goalsStr);
		//window.draw(timerBox);
		window.draw(time);
		window.display();
		sf::sleep(sf::milliseconds(500));



	}
	else if (!scored) {
		isShot = false;
		ball.setPosition(Vector2f(840.0f, 1320.0f));
	}



}



