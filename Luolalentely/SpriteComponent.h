#ifndef	SPRITECOMPONENT_H
#define SPRITECOMPONENT_H
#include <SFML\Graphics.hpp>
#include "GameComponent.h"


class SpriteComponent : public GameComponent
{
public:
	SpriteComponent();
	~SpriteComponent();
	void update(sf::Time &elapsed);
	void draw();
private:
	sf::Sprite sprite;
};

#endif