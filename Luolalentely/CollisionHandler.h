#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H
#include <Box2D\Box2D.h>
#include "GameObject.h"

class CollisionHandler : public b2ContactListener
{
public:
	CollisionHandler();
	~CollisionHandler();

	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);

private:

	void handleCollision(GameObject* objectA, GameObject* objectB);
};

#endif
