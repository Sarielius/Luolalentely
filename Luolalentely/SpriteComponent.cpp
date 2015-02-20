#include "SpriteComponent.h"


SpriteComponent::SpriteComponent(GameObject* g, sf::Texture &sprite) : GameComponent(g), sprite(sprite)
{
}


SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::update(sf::Time &elapsed)
{


}

void SpriteComponent::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}