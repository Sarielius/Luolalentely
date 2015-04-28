#include "GameObject.h"


GameObject::GameObject(Game *game) : game(game)
{
}


GameObject::~GameObject() // Tuhoaa components vektorin sisällön
{
	for (auto &component : components)
	{
		delete component;
	}

	components.clear();

}

void GameObject::update(sf::Time &elapsed) // Päivittää koko vektorin komponentteja.
{
	for (auto &component : components)
	{
		component->update(elapsed);
	}

}

void GameObject::draw(sf::RenderWindow& win) // Piirtää components vektorin sisällön ikkunaan.
{
	for (size_t i = 0; i < components.size(); i++) {
		components[i]->draw(win);
	}
	
}

void GameObject::pushComponent(GameComponent* compo) // Lisää vektoriin komponentteja. 
{
	components.push_back(compo);
}

Game* GameObject::getGame()
{
	return game;
}