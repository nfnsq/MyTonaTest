#pragma once
#include "Object.h"
#include "Globals.h"

class Background : public Object {
public:
	void Init() {
		_sprite.setTextureRect(sf::IntRect(0, 0, WIDTH, HEIGHT));
		_rect = sf::FloatRect(0, 0, 0, 0);
		Object::Init();
		_texture.loadFromFile("resources/background.png");
		_sprite.setPosition(_rect.left, _rect.top);
	}
};