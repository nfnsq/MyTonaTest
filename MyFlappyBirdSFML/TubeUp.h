#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Globals.h"

class TubeUp : public Object
{
public:
	TubeUp() {
		randomHeightTable = {0.18, 0.20, 0.22};
	}

	void Init() {
		_sprite.setTextureRect(sf::IntRect(604, 160, 51, 110));
		_rect = sf::FloatRect(WIDTH - _rect.width - 5, 0, 51, 110);

		Object::Init();
	}

	void SetVelocityX(float v) {
		this->_velocityX = v;
	}

	void SetPosition(int x, int y) {
		this->_rect.left = x;
		this->_rect.top = y;
	}

	void RandomHeight() {
		_rect.height = randomHeightTable[rand() % 3];
		Object::Init();
	}
	
	~TubeUp(){

	}


private:
	std::vector<double> randomHeightTable;
};