#pragma once

#include "Object.h"
#include "Globals.h"

class GameOver : public Object {
public:
	void Init() {
		_sprite.setTextureRect(sf::IntRect(292, 393, 188, 47));
		_rect = sf::FloatRect(WIDTH / 2, HEIGHT / 2, 0, 0);
		Object::Init();
		_sprite.setPosition(_rect.left - _rect.width / 2, _rect.top - _rect.height / 2);
	}
};