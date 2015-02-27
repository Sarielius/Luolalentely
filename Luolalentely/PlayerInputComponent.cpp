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
	const float speed = 20.f;

	b2Vec2 velocity(0, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x = -speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x = speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		velocity.y = -speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		velocity.y = speed;
	}

	getOwner()->getComponent<ColliderComponent>()->getBody()->SetLinearVelocity(velocity);
}

void PlayerInputComponent::draw()
{
	
}