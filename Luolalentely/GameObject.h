#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/Graphics.hpp>
#include "GameComponent.h"
#include "Game.h"

enum TYPES
{
	PLAYER = 0,
	WALL,
	GOAL
};

class GameObject
{
public:
	GameObject(Game *game);
	~GameObject();
	void update(sf::Time &elapsed);
	void draw(sf::RenderWindow& win);
	void pushComponent(GameComponent* compo);
	Game* getGame();

	template<class T>
	T* getComponent() 
	{
		for (unsigned int i = 0; i < components.size(); i++) 
		{
			GameComponent* c = components[i];
			if (typeid(T) == typeid(*c))
				return static_cast<T*>(c);
		}
		return nullptr;
	}

	TYPES type;

private:
	std::vector<GameComponent*> components;
	Game* game;
};

#endif
