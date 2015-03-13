#include "PlayerInputComponent.h"
#include "GameObject.h"
#include "ColliderComponent.h"

#define RADTODEG 57.295779513082320876f

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
	angle *= RADTODEG;
	float rotation = 0.f;
	

	b2Vec2 velocity(0,0);

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
		velocity.x = cos(angle) * speed;
		velocity.y = sin(angle) * speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
			velocity.y = speed;
	}



	getOwner()->getComponent<ColliderComponent>()->getBody()->ApplyAngularImpulse(rotation, true);
	getOwner()->getComponent<ColliderComponent>()->getBody()->ApplyForce(velocity, getOwner()->getComponent<ColliderComponent>()->getBody()->GetWorldCenter(), true);
	
}

void PlayerInputComponent::draw()
{
	
}