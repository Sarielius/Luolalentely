#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H
#include <Box2D\Box2D.h>

class ColliderComponent
{
public:
	ColliderComponent();
	~ColliderComponent();
private:
	b2Body *collider;
};

#endif
