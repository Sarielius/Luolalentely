#include "GoalComponent.h"
#include "GoalSpriteComponent.h"
#include "Convert.h"
#include "GameObject.h"
#define RADTODEG 57.295779513082320876f


GoalComponent::GoalComponent(GameObject* g, b2World &world, sf::FloatRect dimensions) : GameComponent(g), world(world)
{
	GoalSpriteComponent *temp = getOwner()->getComponent<GoalSpriteComponent>();
	if (temp)
	{
		sprite = temp->getSprite();
	}

	b2BodyDef def;
	def.fixedRotation = true;
	def.type = b2_staticBody;
	def.position = Convert::worldToBox2d(dimensions.left, dimensions.top);
	goalCollider = world.CreateBody(&def);
	b2PolygonShape goalShape;
	goalShape.SetAsBox(Convert::worldToBox2d(dimensions.width), Convert::worldToBox2d(dimensions.height));
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &goalShape;
	goalCollider->CreateFixture(&fixtureDef);

	goalCollider->SetUserData(g);

	b2Vec2 pos = Convert::box2dToWorld(goalCollider->GetPosition());
}


GoalComponent::~GoalComponent()
{
	world.DestroyBody(goalCollider);
}

void GoalComponent::update(sf::Time &elapsed)
{
	if (sprite)
	{
		b2Vec2 pos = Convert::box2dToWorld(goalCollider->GetPosition());
		sprite->setPosition(pos.x, pos.y);

		sprite->setRotation(goalCollider->GetAngle()*RADTODEG);
	}
}

void GoalComponent::draw()
{

}

b2Body* GoalComponent::getBody()
{
	return goalCollider;
}