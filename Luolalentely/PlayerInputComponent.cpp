#include "PlayerInputComponent.h"
#include "GameObject.h"
#include "ColliderComponent.h"
#include "GameplayState.h"

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f


PlayerInputComponent::PlayerInputComponent(GameObject* g) : GameComponent(g)
{}

PlayerInputComponent::~PlayerInputComponent()
{}

void PlayerInputComponent::update(sf::Time &elapsed)
{ 
	const float speed = 1.0f; //Asetetaan "pohja"nopeus
	float angle = getOwner()->getComponent<ColliderComponent>()->getBody()->GetAngle(); //Haetaan aluksen kulma.
	float rotation = 0.f; //Alustetaan rotaatiovoima
	

	b2Vec2 velocity(0,0); //Tehdään nopeusvektori joka ottaa X ja Y arvot.

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		rotation = -0.009f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		rotation = 0.009f; 
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
	{ //Laskut nopeuden lisäämiseksi objektin kärjen suuntaan.
		velocity.x = sin(angle) * speed ;
		velocity.y = cos(angle) * -speed ;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) //Reset
	{
		GameObject *owner = getOwner();
		owner->getGame()->getStateManager()->doNextUpdate([owner]()
		{
			owner->getGame()->getStateManager()->change(new GameplayState(owner->getGame()));
		});
	}

	

	getOwner()->getComponent<ColliderComponent>()->getBody()->ApplyAngularImpulse(rotation, true); //Annetaan kulmaimpulssi rotationin mukaisesti.
	getOwner()->getComponent<ColliderComponent>()->getBody()->ApplyForce(velocity, getOwner()->getComponent<ColliderComponent>()->getBody()->GetWorldCenter(), true);
	
	
}

void PlayerInputComponent::draw()
{
	
}