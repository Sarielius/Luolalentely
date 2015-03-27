#ifndef WALLSPRITECOMPONENT_H
#define WALLSPRITECOMPONENT_H
#include "GameComponent.h"

class WallSpriteComponent : public GameComponent
{
public:
	WallSpriteComponent(GameObject*, sf::Texture&, float x, float y);
	~WallSpriteComponent();
	void update(sf::Time &elapsed);
	void draw(sf::RenderWindow &window);

	sf::Sprite* getSprite();
private:
	sf::Sprite wallSprite;
};

#endif
