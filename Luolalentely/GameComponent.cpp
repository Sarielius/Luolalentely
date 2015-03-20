#include "GameComponent.h"
#include <cassert>

GameComponent::GameComponent(GameObject* g) : owner(g)
{
	assert(g != nullptr);
}


GameComponent::~GameComponent()
{
}

void GameComponent::update(sf::Time &elapsed)
{
}
void GameComponent::draw(sf::RenderWindow& win)
{
}

GameObject* GameComponent::getOwner() 
{
	return owner;
}