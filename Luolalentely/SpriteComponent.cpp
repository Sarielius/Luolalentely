#include "SpriteComponent.h"
#include "Convert.h"
#include "GameObject.h"
#include "ColliderComponent.h"

SpriteComponent::SpriteComponent(GameObject* g, sf::Texture &sprite) : GameComponent(g), sprite(sprite)
{
}


SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::update(sf::Time &elapsed)
{
	b2Vec2 pos = Convert::box2dToWorld(getOwner()->getComponent<ColliderComponent>()->getBody()->GetPosition());
	sprite.setPosition(pos.x, pos.y);
}

void SpriteComponent::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}