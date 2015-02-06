#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H
#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

class ColliderComponent
{
public:
	ColliderComponent();
	~ColliderComponent();
	void update(sf::Time &elapsed);
	void draw();
private:
	b2Body *collider;
};

#endif