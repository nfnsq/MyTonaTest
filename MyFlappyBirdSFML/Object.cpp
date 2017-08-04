#include "Object.h"

Object::Object() {

	_velocityX = 0.0;
	_velocityY = 0.0;

	_accelerationX = 0.0;
	_accelerationY = 0.0;

	_ID = -1;

	_rect = sf::FloatRect(0, 0, 0, 0);

}

Object::~Object()
{
	Destroy();
}

int Object::GetWidth() { 
	return this->_rect.width; 
}

int Object::GetHeight() { 
	return this->_rect.height; 
}

int Object::GetX() { 
	return this->_rect.left; 
}

int Object::GetY() { 
	return this->_rect.top; 
}

sf::Sprite Object::GetSprite()
{
	return this->_sprite;
}

bool Object::Collision(const Object & obj) const
{
	if ((this->_rect.left < (obj._rect.width + obj._rect.left)) 
		&& ((this->_rect.left + this->_rect.width) > obj._rect.left)
		&& (this->_rect.top < (obj._rect.height + obj._rect.top))
		&& ((this->_rect.top + this->_rect.height) > obj._rect.top))
	{
		return true;
	}
	return false;
}

void Object::Init()
{
	_texture.loadFromFile("resources/fbirdsprite.png");
	sf::IntRect spriteRect = _sprite.getTextureRect();
	_sprite.setTexture(_texture);
	_rect.width = spriteRect.width;
	_rect.height = spriteRect.height;
}

void Object::Update(float time)
{
	_velocityX += _accelerationX * time;
	_velocityY += _accelerationY * time;

	_rect.left += _velocityX * time;
	_rect.top += _velocityY * time;

	_sprite.setPosition(_rect.left, _rect.top);

}

void Object::Destroy()
{
}

void Object::Render(sf::RenderWindow * window) {
	window->draw(_sprite);
}
