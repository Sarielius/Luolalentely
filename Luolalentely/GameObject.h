#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <Box2D\Box2D.h>
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject();
	~GameObject();
	void update(sf::Time &elapsed);
	void draw();
private:
	b2Body *collider;
};

#endif
