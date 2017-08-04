#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Text {
public:
	Text(sf::Font font, std::string text, float pos_x, float pos_y) {
		this->font = font;
		this->text = text;
		this->pos_x = pos_x;
		this->pos_y = pos_y;
	}

	void setPosition(int x, int y) {
		pos_x = x;
		pos_y = y;
	}

	void setColor(sf::Color color) {
		_color = color;
	}

	void setText(std::string text) {
		this->text = text;
	}

	void draw(sf::RenderWindow * window) {
		sf::Text* t = new sf::Text(text, font, 30);
		t->setPosition(pos_x, pos_y);
		t->setFillColor(_color);
		window->draw(*t);
	}

private:
	std::string text;
	sf::Font font;
	sf::Color _color;
	float pos_x, pos_y;
};