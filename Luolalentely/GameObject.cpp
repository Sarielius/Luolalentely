#include "GameObject.h"


GameObject::GameObject(Game *game) : game(game)
{
}


GameObject::~GameObject() // Destroys all components and clears the storage
{
	for (auto &component : components)
	{
		delete component;
	}

	components.clear();

}

void GameObject::update(sf::Time &elapsed) // Updates all components
{
	for (auto &component : components)
	{
		component->update(elapsed);
	}

}

void GameObject::draw(sf::RenderWindow& win) // Draws the content of the component vector
{
	for (size_t i = 0; i < components.size(); i++) {
		components[i]->draw(win);
	}
}

void GameObject::pushComponent(GameComponent* compo) // Adds components
{
	components.push_back(compo);
}

Game* GameObject::getGame()
{
	return game;
}