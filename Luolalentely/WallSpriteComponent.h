#ifndef WALLSPRITECOMPONENT_H
#define WALLSPRITECOMPONENT_H
#include "GameComponent.h"

class WallSpriteComponent : public GameComponent
{
public:
	WallSpriteComponent(GameObject*, sf::Texture&);
	~WallSpriteComponent();
	void update(sf::Time &elapsed);
	void draw(sf::RenderWindow &window);
private:
	sf::Sprite wallSprite;
};

#endif
