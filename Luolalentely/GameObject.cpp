#include "GameObject.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
	for (auto &component : components)
	{
		delete component;
	}

	components.clear();
}

void GameObject::update(sf::Time &elapsed)
{
	for (auto &component : components)
	{
		component->update(elapsed);
	}

}

void GameObject::draw(sf::RenderWindow& win)
{
	for (size_t i = 0; i < components.size(); i++) {
		components[i]->draw(win);
	}
	
}

void GameObject::pushComponent(GameComponent* compo)
{
	components.push_back(compo);
}