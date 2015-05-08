#include "CollisionHandler.h"
#include "WinState.h"
#include "GameOverState.h"
#include "PlayerInputComponent.h"
#include "HealthComponent.h"
#include "ColliderComponent.h"

CollisionHandler::CollisionHandler()
{
}


CollisionHandler::~CollisionHandler()
{
}

void CollisionHandler::BeginContact(b2Contact* contact)
{
	handleCollision(static_cast<GameObject*>(contact->GetFixtureA()->GetBody()->GetUserData()), 
		static_cast<GameObject*>(contact->GetFixtureB()->GetBody()->GetUserData()));
}

void CollisionHandler::EndContact(b2Contact* contact)
{}


void CollisionHandler::handleCollision(GameObject* objectA, GameObject* objectB)
{
	if (objectA->type == TYPES::PLAYER && objectB->type == TYPES::GOAL || objectB->type == TYPES::PLAYER && objectA->type == GOAL)
	{
		objectA->getGame()->getStateManager()->doNextUpdate([objectA]() 
		{
			objectA->getGame()->getStateManager()->change(new WinState(objectA->getGame()));
		});
	}
	else if (objectA->type == TYPES::PLAYER && objectB->type == TYPES::WALL)
	{
		if (objectA->getComponent<HealthComponent>()->alive)
		{
			objectA->getComponent<HealthComponent>()->setHealth(-0.02f*objectA->getComponent<ColliderComponent>()->getBody()->GetLinearVelocity().Length());


			if (!objectA->getComponent<HealthComponent>()->alive)
			{
				objectA->getGame()->getStateManager()->doNextUpdate([objectA]()
				{
					objectA->getGame()->getStateManager()->change(new GameOverState(objectA->getGame()));
				});
			}
		}
	}
	else if (objectB->type == TYPES::PLAYER && objectA->type == WALL)
	{
		if (objectB->getComponent<HealthComponent>()->alive)
		{
			objectB->getComponent<HealthComponent>()->setHealth(-0.02f*objectB->getComponent<ColliderComponent>()->getBody()->GetLinearVelocity().Length());

			if (!objectB->getComponent<HealthComponent>()->alive)
			{
				objectB->getGame()->getStateManager()->doNextUpdate([objectB]()
				{
					objectB->getGame()->getStateManager()->change(new GameOverState(objectB->getGame()));
				});
			}
		}
	}
}