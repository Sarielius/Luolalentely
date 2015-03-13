#include "PlayerInputComponent.h"
#include "GameObject.h"
#include "ColliderComponent.h"
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f


PlayerInputComponent::PlayerInputComponent(GameObject* g) : GameComponent(g)
{

}


PlayerInputComponent::~PlayerInputComponent()
{

}

void PlayerInputComponent::update(sf::Time &elapsed)
{ 
	const float speed = 20.f;
	float angle = getOwner()->getComponent<ColliderComponent>()->getBody()->GetAngle();
	float rotation = 0.f;
	

	b2Vec2 velocity(0,0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		rotation = -0.005f; 
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		rotation = 0.005f; 
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		velocity.x = sin(angle) * speed ;
		velocity.y = cos(angle) * -speed ;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		getOwner()->getGame()->window.close();
	}

	velocity.Normalize();
	getOwner()->getComponent<ColliderComponent>()->getBody()->ApplyAngularImpulse(rotation, true);
	getOwner()->getComponent<ColliderComponent>()->getBody()->ApplyForce(velocity, getOwner()->getComponent<ColliderComponent>()->getBody()->GetWorldCenter(), true);
	
}

void PlayerInputComponent::draw()
{
	
}