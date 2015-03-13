#include "SpriteComponent.h"
#include "Convert.h"
#include "GameObject.h"
#include "ColliderComponent.h"
#define RADTODEG 57.295779513082320876f

SpriteComponent::SpriteComponent(GameObject* g, sf::Texture &sprite) : GameComponent(g), sprite(sprite)
{
	this->sprite.setOrigin(sprite.getSize().x / 2, sprite.getSize().y / 2);
}


SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::update(sf::Time &elapsed)
{
	// Asetetaan spriten asemaksi gameobjectin keskipiste. 
	b2Vec2 pos = Convert::box2dToWorld(getOwner()->getComponent<ColliderComponent>()->getBody()->GetPosition());
	sprite.setPosition(pos.x, pos.y);
	
	sprite.setRotation(getOwner()->getComponent<ColliderComponent>()->getBody()->GetAngle()*RADTODEG);
}

void SpriteComponent::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}