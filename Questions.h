#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/System.hpp>
#include<vector>
using namespace std;
// Question class to handle each question and its options

class Questions {
public:
	sf::Font font;
	string question;
	vector<string> options;
	int correctAnswerIndex = 0;
	bool vertical;
	vector<sf::Color> optionColor;

	Questions(const string& question, const vector<string> opts, int correctIndex, bool vertical);
	sf::Text questionAsText();
	vector<sf::Text> optionsAsText();

};