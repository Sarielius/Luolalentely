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
	const float speed = 5.f;
	float angle = getOwner()->getComponent<ColliderComponent>()->getBody()->GetAngle();
	float rotation = 0.f;
	

	b2Vec2 velocity(0, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		rotation = -1.5f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		rotation = 1.5f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		velocity.y = -speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (velocity.y != 0)
		{
			velocity.y = speed;
		}
		
	}



	getOwner()->getComponent<ColliderComponent>()->getBody()->ApplyAngularImpulse(rotation, true);
	getOwner()->getComponent<ColliderComponent>()->getBody()->ApplyForce(velocity, getOwner()->getComponent<ColliderComponent>()->getBody()->GetWorldCenter(), true);
	//getOwner()->getComponent<ColliderComponent>()->getBody()->SetLinearVelocity(velocity);
	
}

void PlayerInputComponent::draw()
{
	
}