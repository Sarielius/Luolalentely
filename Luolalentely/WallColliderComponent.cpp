#include "WallColliderComponent.h"
#include "Convert.h"

WallColliderComponent::WallColliderComponent(GameObject* g, b2World &world, sf::FloatRect dimensions) : GameComponent(g), world(world)
{
	b2BodyDef def;
	def.fixedRotation = true;
	def.type = b2_staticBody;
	def.position = Convert::worldToBox2d(dimensions.left, dimensions.top);
	wallCollider = world.CreateBody(&def);
	b2PolygonShape wallShape;
	wallShape.SetAsBox(Convert::worldToBox2d(dimensions.width), Convert::worldToBox2d(dimensions.height));
	b2FixtureDef FixtureDef;
	FixtureDef.shape = &wallShape;
	wallCollider->CreateFixture(&FixtureDef);
}


WallColliderComponent::~WallColliderComponent()
{
	world.DestroyBody(wallCollider);
}

void WallColliderComponent::update(sf::Time &elapsed)
{

}

void WallColliderComponent::draw()
{
	
}
b2Body *WallColliderComponent::getBody()
{
	return wallCollider;
}