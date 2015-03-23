#ifndef WALLCOLLIDERCOMPONENT_H
#define WALLCOLLIDERCOMPONENT_H
#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>
#include "GameComponent.h"


class WallColliderComponent : public GameComponent
{
public:
	WallColliderComponent(GameObject*, b2World&, sf::FloatRect);
	~WallColliderComponent();
	void update(sf::Time &elapsed);
	void draw();
	b2Body* getBody();
private:
	b2World &world;
	b2Body *wallCollider;
};

#endif
