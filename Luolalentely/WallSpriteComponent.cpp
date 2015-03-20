#include "WallSpriteComponent.h"


WallSpriteComponent::WallSpriteComponent(GameObject *g, sf::Texture &wallSprite) : GameComponent(g), wallSprite(wallSprite)
{
	this->wallSprite.setOrigin(wallSprite.getSize().x / 2, wallSprite.getSize().y / 2);
}


WallSpriteComponent::~WallSpriteComponent()
{
}

void WallSpriteComponent::update(sf::Time &elapsed)
{

}

void WallSpriteComponent::draw(sf::RenderWindow &window)
{
	window.draw(wallSprite);
}
