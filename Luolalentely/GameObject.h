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
	void draw(sf::RenderWindow& win);
	void pushComponent(GameComponent* compo);

	template<class T>
	T* getComponent() 
	{
		for (int i = 0; i < components.size(); i++) 
		{
			GameComponent* c = components[i];
			if (typeid(T) == typeid(*c))
				return static_cast<T*>(c);
		}
		return nullptr;
	}


private:
	std::vector<GameComponent*> components;
};

#endif
