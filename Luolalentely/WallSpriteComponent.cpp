#include "WallSpriteComponent.h"
#include <Box2D\Box2D.h>
#include "Convert.h"
#include "GameObject.h"
#include "WallColliderComponent.h"

WallSpriteComponent::WallSpriteComponent(GameObject *g, sf::Texture &wallSprite) : GameComponent(g), wallSprite(wallSprite)
{
	this->wallSprite.setOrigin(wallSprite.getSize().x / 2, wallSprite.getSize().y / 2);

	b2Vec2 pos = Convert::box2dToWorld(getOwner()->getComponent<WallColliderComponent>()->getBody()->GetPosition());
	this->wallSprite.setPosition(pos.x, pos.y);

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
