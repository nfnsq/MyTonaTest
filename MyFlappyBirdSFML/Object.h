#pragma once
#include <SFML/Graphics.hpp>

class Object
{
public:
	int GetWidth();
	int GetHeight();
	int GetX();
	int GetY();
	sf::Sprite GetSprite();
	bool Collision(const Object& obj) const;
	
	virtual void Init();
	virtual void Update(float time);
	virtual void Destroy();
	virtual void Render(sf::RenderWindow * window);

	Object();
	~Object();

protected:

	float _velocityX;
	float _velocityY;
	
	float _accelerationX;
	float _accelerationY;
	
	int _ID;

	sf::Sprite _sprite;
	sf::FloatRect _rect;
	sf::Texture _texture;
};