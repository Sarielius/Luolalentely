#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/Graphics.hpp>
#include "GameComponent.h"

class GameObject
{
public:
	GameObject();
	~GameObject();
	void update(sf::Time &elapsed);
	void draw();
	void pushComponent(GameComponent* compo);

private:
	std::vector<GameComponent*> components;
};

#endif
