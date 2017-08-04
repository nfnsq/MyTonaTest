#pragma once
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Globals.h"
#include "Text.h"


class HighScores {
public:
	HighScores(sf::RenderWindow * window) {
		this->_window = window;
		this->Init();
	}

	~HighScores() {
		Destroy();
	}
	void Init() {
		_background = new Background();

		_background->Init();

		GetScoreList();

		_showList = true;
	}

	void Destroy() {
		if (_background != NULL) {
			delete _background;
		}
		_background = NULL;
	}
	
	void AddScoreToList(int newScore) {
 		if (newScore > _scoreList[_scoreList.size() - 1])
		{
			if (_scoreList.size() > 4)
			{
				_scoreList.erase(_scoreList.end() - 1);
			}
			_scoreList.push_back(newScore);
		}
		std::sort(_scoreList.begin(), _scoreList.end());
		std::reverse(_scoreList.begin(), _scoreList.end());
		std::ofstream _file("scores.txt", std::ios::out | std::ios::trunc);
		if (!_file.is_open())
		{
			std::cout << "Scores file could not opened." << std::endl;
		}
		else
		{
			_file.clear();
			for (int i = 0; i < 4; i++)
			{
				_file << _scoreList[i] << std::endl;
			}
			_file << _scoreList[4];
		}
		_file.close();
	}

	void Render() {
		_window->clear(sf::Color::White);
		_background->Render(_window);
		for (int i = 0; i < _scoreList.size(); i++)
		{
			sf::Font font;
			font.loadFromFile("resources/font.ttf");
			sf::Text* text = new sf::Text(std::to_string(_scoreList[i]), font);
			text->setFillColor(sf::Color::Green);
			text->setCharacterSize(22);
			text->setPosition(WIDTH / 2, 100 + i * 40);
			_window->draw(*text);
			delete text;
		}
		DrawTitle();
		_window->display();
	}

	void HandleEvents() {
		sf::Event event;
		while ((*_window).pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				_showList = false;
				(*_window).close();
			}
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				_showList = false;
				this->Destroy();
				return;
				break;
			default:
				break;
			}
		}
	}

	void Run() {
		this->Init();
		this->HandleEvents();
		this->Render();
	}
private:
	Background* _background;
	std::vector<int> _scoreList;
	sf::RenderWindow * _window;
	bool _showList;

	void GetScoreList() {
		this->_scoreList.clear();

		std::ifstream _file("scores.txt", std::ios::in);
		if (!_file.is_open())
		{
			std::cout << "Scores file could not opened." << std::endl;
		}
		else
		{
			int bufer;
			while (!_file.eof())
			{
				_file >> bufer;
				_scoreList.push_back(bufer);
			}
		}
		_file.close();
	}

	void DrawTitle()
	{
		std::string titleString = "HIGH SCORES";
		sf::Font font;
		font.loadFromFile("resources/font.ttf");
		sf::Text* title = new sf::Text(titleString, font, 30);
		title->setPosition(WIDTH/2 - 80, 40);
		_window->draw(*title);
	}
};