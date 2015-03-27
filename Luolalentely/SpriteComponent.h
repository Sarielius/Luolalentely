#ifndef	SPRITECOMPONENT_H
#define SPRITECOMPONENT_H
#include <SFML\Graphics.hpp>
#include "GameComponent.h"


class SpriteComponent : public GameComponent
{
public:
	SpriteComponent(GameObject*, sf::Texture&);
	~SpriteComponent();
	void update(sf::Time &elapsed);
	void draw(sf::RenderWindow &window);
	sf::Sprite* getSprite();
private:
	sf::Sprite sprite;
};

#endif