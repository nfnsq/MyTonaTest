#pragma once
#include "SFML/Graphics.hpp"
#include "Background.h"
#include "Text.h"

enum ActionMenu { NEWGAME, SCORES, QUIT };

struct PositionMenu {
	PositionMenu(Text* text) {
		this->text = text;
		if (text) {
			default();
		}
	}
	~PositionMenu() {
		if (text) {
			delete text;
		}
	}

	void active() {
		text->setColor(sf::Color::Yellow);
	}
	void default() {
		text->setColor(sf::Color::White);
	}
	void SetPosition(int x, int y) {
		text->setPosition(x, y);
	}

	void draw(sf::RenderWindow * window) {
		text->draw(window);
	}

	ActionMenu action;
private:
	Text* text;

};

struct PositionManager {
public:
	PositionManager(int posx, int posy, int space) {
		this->space = space;
		x = posx;
		y = posy;
		next_x = x;
		next_y = y;
		current = 0;
	}

	~PositionManager() {
		for (int i = 0; i < positions.size(); ++i) {
			if (positions[i])
				delete positions[i];
		}
		positions.clear();
	}

	void addPosition(std::string text, ActionMenu action) {
		
		sf::Font font;
		font.loadFromFile("resources/font.ttf");
		positions.push_back(new PositionMenu(new Text(font, text, next_x, next_y)));
		positions[positions.size() - 1]->action = action;
		next_y += space;
		if (positions.size() == 1) positions[0]->active();
	}

	void draw(sf::RenderWindow * window) {
		for (int i = 0; i < positions.size(); ++i) {
			positions[i]->SetPosition(WIDTH / 3, HEIGHT / 4 + i * 80);
			positions[i]->draw(window);
		}
	}

	void up() {
		if (positions.size() == 0) return;
		positions[current]->default();
		if (current == 0) current = positions.size() - 1;
		else --current;
		positions[current]->active();
	}
	void down() {
		if (positions.size() == 0) return;
		positions[current]->default();
		if (current == positions.size() - 1) current = 0;
		else ++current;
		positions[current]->active();
	}

	ActionMenu getCurrentAction() {
		return positions[current]->action;
	}

private:
	int space;
	std::vector<PositionMenu*> positions;
	int x, y;
	int next_x, next_y;
	int current;
	static const std::string fontName;
};

class Menu {
public:
	Menu(sf::RenderWindow * _window_point) : _manager(200, 200, 5), _background() {
		_window = _window_point;
		_background.Init();
		_manager.addPosition("New Game", NEWGAME);
		_manager.addPosition("High Scores", SCORES);
		_manager.addPosition("Quit", QUIT);
	}

	~Menu() {
	}

	void Render() {
		_window->clear(sf::Color::White);
		_background.Render(_window);
		_manager.draw(_window);
		ActionMenu a = Action();
		switch (a) {
		case NEWGAME: drawInfo("Start new game"); break;
		case SCORES: drawInfo("View high scores"); break;
		case QUIT: drawInfo("Close Apppication"); break;
		}		

		_window->display();
	}

	void Up() {
		_manager.up();
	}

	void Down() {
		_manager.down();
	}

	ActionMenu Action() {
		return _manager.getCurrentAction();
	}

private:
	PositionManager _manager;
	Background _background;
	sf::RenderWindow * _window;
		
	void drawInfo(std::string info) {
		sf::Font font;
		font.loadFromFile("resources/font.ttf");
		sf::Text* infoText = new sf::Text(info, font);
		infoText->setFillColor(sf::Color::Blue);
		infoText->setCharacterSize(20);
		infoText->setPosition(WIDTH * 3 / 4, HEIGHT * 4 / 5);
		_window->draw(*infoText);
		delete infoText;
	}
};