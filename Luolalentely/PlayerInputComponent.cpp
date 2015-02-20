#include "PlayerInputComponent.h"
#include "GameObject.h"
#include "ColliderComponent.h"

PlayerInputComponent::PlayerInputComponent(GameObject* g) : GameComponent(g)
{

}


PlayerInputComponent::~PlayerInputComponent()
{

}

void PlayerInputComponent::update(sf::Time &elapsed)
{
	b2Vec2 velocity(0, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{

	}

	getOwner()->getComponent<ColliderComponent>()->getBody()->SetLinearVelocity(velocity);
}

void PlayerInputComponent::draw()
{
	
}