#pragma once

#include <SFML/Graphics.hpp>
#include "Bird.h"
#include "TubeDown.h"
#include "TubeUp.h"
#include "ScrollTubes.h"
#include "GameOver.h"
#include "Background.h"
#include "HighScores.h"

class Game
{
public:
	Game(sf::RenderWindow * window_point) {
		_window = window_point;
		this->Init();
	}

	~Game() {
		this->Destroy();
	}	

	void Init() {
		Destroy();
		_background = new Background();
		_bird = new Bird();
		_scrollTubes = new ScrollTubes(_bird);
		_gameOverPic = new GameOver();
		_highScores = new HighScores(_window);
		_background->Init();
		_bird->Init();
		_gameOverPic->Init();


		_gameOver = false;
		_realGameOver = false;
		_is_game_running = true;
		_write_score = true;
	}

	void Destroy()
	{
		if (_background != NULL) {
			delete _background;
		}
		if (_bird != NULL) {
			delete _bird;
		}
		if (_scrollTubes != NULL) {
			delete _scrollTubes;
		}
		if (_gameOverPic != NULL) {
			delete _gameOverPic;
		}
		if (_highScores != NULL) {
			delete _highScores;
		}
		_background = NULL;
		_bird = NULL;
		_scrollTubes = NULL;
		_gameOverPic = NULL;
		_highScores = NULL;
	}

	void Render() {
		if (_is_game_running)
		{
			_window->clear(sf::Color::White);
			_background->Render(_window);
			_window->draw(_bird->GetSprite());
			_scrollTubes->Render(_window);
			if (_realGameOver) {
				_window->draw(_gameOverPic->GetSprite());
				std::string messageString = "Press enter to try again";
				sf::Font font;
				font.loadFromFile("resources/font.ttf");
				sf::Text* message = new sf::Text(messageString, font, 26);
				message->setPosition(WIDTH / 3 , 220);
				_window->draw(*message); 
			}
			ShowPoints();
			_window->display();
		}
	}

	void HandleEvents() {
		sf::Event event;
		while ((*_window).pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				_is_game_running = false;
				(*_window).close();
			}
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				_is_game_running = false;
				this->Destroy();
				return;
				break;
			case sf::Keyboard::Space:
				if (!_gameOver) {
					(*_bird).Jump();
					(*_scrollTubes).StartScroll();
				}
				break;
			case sf::Keyboard::Return:
				this->Run();
				break;
			default:
				break;
			}
		}
	}

	void Update(float timer) {
		if (_is_game_running)
		{
			_background->Update(timer);
			_scrollTubes->Update(timer);
			_bird->Update(timer);
			if (_scrollTubes->Collision(*_bird) || (_bird->GetY() < 0)
				|| (_bird->GetY() + _bird->GetHeight() > HEIGHT)) {
				_gameOver = true;
				_scrollTubes->StopScroll();

			}
			if (_gameOver == true) {
				if (_bird->GetY() + _bird->GetHeight() + 2 >= HEIGHT) {
					_bird->Stop();
					_realGameOver = true;
				}
				if (_write_score) {
					_highScores->AddScoreToList(_bird->GetScore());
					_write_score = false;
				}
			}
		}
	}

	void Run() {
		sf::Clock clock;
		this->Init();
		while (_is_game_running)
		{
			float time = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time = time / 800;
			
			this->HandleEvents();
			
			this->Update(time);

			this->Render();
		}
	}


private:
	Background* _background;
	Bird* _bird;
	ScrollTubes* _scrollTubes;
	GameOver* _gameOverPic;
	HighScores* _highScores;
	bool _gameOver;
	bool _realGameOver;
	sf::RenderWindow * _window;
	bool _is_game_running;
	bool _write_score;


	void ShowPoints() {
		std::string scoreText = "SCORE: " + std::to_string(_bird->GetScore());
		sf::Font font;
		font.loadFromFile("resources/font.ttf");
		sf::Text* score = new sf::Text(scoreText, font, 30);
		score->setPosition(10, 10);
		_window->draw(*score);
	}
};

