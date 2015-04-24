#include "GoalSpriteComponent.h"
#include "GoalComponent.h"
#include "GameObject.h"


GoalSpriteComponent::GoalSpriteComponent(GameObject *g, sf::Texture &goalSprite, float x, float y) : GameComponent(g), goalSprite(goalSprite)
{
	this->goalSprite.setOrigin(goalSprite.getSize().x / 2, goalSprite.getSize().y / 2);
	this->goalSprite.setPosition(x, y);
}


GoalSpriteComponent::~GoalSpriteComponent()
{
}

void GoalSpriteComponent::update(sf::Time &elapsed)
{

}

void GoalSpriteComponent::draw(sf::RenderWindow &window)
{
	window.draw(goalSprite);
}

 sf::Sprite* GoalSpriteComponent::getSprite()
{
	return &goalSprite;
}
