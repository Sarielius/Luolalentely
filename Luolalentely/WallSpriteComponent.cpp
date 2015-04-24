#include "WallSpriteComponent.h"
#include "GameObject.h"
#include "WallColliderComponent.h"

WallSpriteComponent::WallSpriteComponent(GameObject *g, sf::Texture &wallSprite, float x, float y) : GameComponent(g), wallSprite(wallSprite)
{
	this->wallSprite.setOrigin(wallSprite.getSize().x / 2, wallSprite.getSize().y / 2);
	this->wallSprite.setPosition(x, y);
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

sf::Sprite* WallSpriteComponent::getSprite()
{
	return &wallSprite;
}
