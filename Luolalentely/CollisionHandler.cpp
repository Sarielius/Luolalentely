#include "CollisionHandler.h"
#include "MenuState.h"


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
{

}


void CollisionHandler::handleCollision(GameObject* objectA, GameObject* objectB)
{
	if (objectA->type == TYPES::PLAYER && objectB->type == TYPES::GOAL || objectB->type == TYPES::PLAYER && objectA->type == GOAL)
		objectA->getGame()->window.close;
		/*objectA->getGame()->getStateManager()->change(new MenuState(objectA->getGame()));*/
}