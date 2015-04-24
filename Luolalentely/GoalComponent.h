#ifndef GOALCOMPONENT_H
#define GOALCOMPONENT_H
#include "GameComponent.h"
#include <Box2D\Box2D.h>

class GoalComponent : public GameComponent
{
public:
	GoalComponent(GameObject*, b2World&, sf::FloatRect);
	~GoalComponent();
	void update(sf::Time &elapsed);
	void draw();
	b2Body* getBody();
private:
	b2World &world;
	b2Body *goalCollider;
	sf::Sprite* sprite;
};

#endif
