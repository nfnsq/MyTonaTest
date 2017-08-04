#pragma once
#include "Object.h"
#include "Globals.h"

#include <SFML/Graphics.hpp>

class Bird : public Object {
public:
	Bird() : Object() {
		_score = 0;
		_currentFrame = 0;
	}

	void Init() {
		_sprite.setTextureRect(sf::IntRect(520, 117 + 50 * int(_currentFrame), 50, 50));
		_rect = sf::FloatRect(WIDTH /2 , HEIGHT / 2, 50, 50);
		Object::Init();
	}

	void Update(float time) {
		Object::Update(time);

		_currentFrame += float(0.005 * time);
		if (_currentFrame > 2) { _currentFrame -= 2; }
		_sprite.setTextureRect(sf::IntRect(520, 117 + 50 * int(_currentFrame), 50, 50));

		_sprite.setPosition(_rect.left, _rect.top);
	}

	void Jump() {
		_velocityY = -0.25f;
		_accelerationY = 0.0005f;
	}

	void Stop() {
		_velocityX = 0;
		_velocityY = 0;
		_accelerationX = 0;
		_accelerationY = 0;
	}

	void Up() { _rect.top -= 10; }
	void Down() { _rect.top += 10; }
	void Left() { _rect.left -= 10; }
	void Right() { _rect.left += 10; }

	void AddPoint() {
		this->_score += 1;
	}
	int GetScore() {
		return this->_score;
	}

private:
	int _score;
	float _currentFrame;

};