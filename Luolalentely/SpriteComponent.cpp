#include "SpriteComponent.h"
#include "Convert.h"
#include "GameObject.h"
#include "CameraComponent.h"


SpriteComponent::SpriteComponent(GameObject* g, sf::Texture &sprite) : GameComponent(g), sprite(sprite)
{ 
	//Asetetaan spriten akselikeskipiste itse keskipisteeseen.
	this->sprite.setOrigin(sprite.getSize().x / 2, sprite.getSize().y / 2); 
}


SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::update(sf::Time &elapsed)
{
}

void SpriteComponent::draw(sf::RenderWindow &window) //Piirt‰‰ spriten ikkunaan.
{
	window.draw(sprite);
}

sf::Sprite* SpriteComponent::getSprite()
{
	return &sprite;
}