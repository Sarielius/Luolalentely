#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H
#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>
#include "GameComponent.h"

class ColliderComponent : public GameComponent
{
public:
	ColliderComponent(GameObject*, b2World&, sf::FloatRect);
	~ColliderComponent();
	void update(sf::Time &elapsed);
	void draw();
	b2Body* getBody();
private:
	b2Body *collider;
	b2World &world;
};

#endif
