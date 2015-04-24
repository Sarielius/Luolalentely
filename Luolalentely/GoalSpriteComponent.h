#ifndef GOALSPRITECOMPONENT_H
#define GOALSPRITECOMPONENT_H
#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>
#include "GameComponent.h"

class GoalSpriteComponent : public GameComponent
{
public:
	GoalSpriteComponent(GameObject*, sf::Texture&, float x, float y);
	~GoalSpriteComponent();
	void update(sf::Time &elapsed);
	void draw(sf::RenderWindow &window);

	sf::Sprite* getSprite();
private:
	sf::Sprite goalSprite;
};

#endif
