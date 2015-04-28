#include "GameObject.h"


GameObject::GameObject(Game *game) : game(game)
{
}


GameObject::~GameObject() // Tuhoaa components vektorin sis�ll�n
{
	for (auto &component : components)
	{
		delete component;
	}

	components.clear();

}

void GameObject::update(sf::Time &elapsed) // P�ivitt�� koko vektorin komponentteja.
{
	for (auto &component : components)
	{
		component->update(elapsed);
	}

}

void GameObject::draw(sf::RenderWindow& win) // Piirt�� components vektorin sis�ll�n ikkunaan.
{
	for (size_t i = 0; i < components.size(); i++) {
		components[i]->draw(win);
	}
	
}

void GameObject::pushComponent(GameComponent* compo) // Lis�� vektoriin komponentteja. 
{
	components.push_back(compo);
}

Game* GameObject::getGame()
{
	return game;
}