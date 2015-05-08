#include "SpriteComponent.h"
#include "Convert.h"
#include "GameObject.h"
#include "CameraComponent.h"


SpriteComponent::SpriteComponent(GameObject* g, sf::Texture &sprite) : GameComponent(g), sprite(sprite)
{ 
	// Sets the sprite's origin to the middle of the texture
	this->sprite.setOrigin(sprite.getSize().x / 2.0f, sprite.getSize().y / 2.0f);
}


SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::update(sf::Time &elapsed)
{
}

void SpriteComponent::draw(sf::RenderWindow &window) 
{
	window.draw(sprite);
}

sf::Sprite* SpriteComponent::getSprite()
{
	return &sprite;
}