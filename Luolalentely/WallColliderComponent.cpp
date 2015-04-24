#include "WallColliderComponent.h"
#include "Convert.h"
#include "WallSpriteComponent.h"
#include "GameObject.h"
#define RADTODEG 57.295779513082320876f

WallColliderComponent::WallColliderComponent(GameObject* g, b2World &world, sf::FloatRect dimensions) : GameComponent(g), world(world)
{
	WallSpriteComponent *temp = getOwner()->getComponent<WallSpriteComponent>();
	if (temp)
	{
		sprite = temp->getSprite();
	}

	b2BodyDef def;
	def.fixedRotation = true;
	def.type = b2_staticBody;
	def.position = Convert::worldToBox2d(dimensions.left, dimensions.top);
	wallCollider = world.CreateBody(&def);
	b2PolygonShape wallShape;
	wallShape.SetAsBox(Convert::worldToBox2d(dimensions.width), Convert::worldToBox2d(dimensions.height));
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &wallShape;
	wallCollider->CreateFixture(&fixtureDef);

	wallCollider->SetUserData(g);

	b2Vec2 pos = Convert::box2dToWorld(wallCollider->GetPosition());
}


WallColliderComponent::~WallColliderComponent()
{
	world.DestroyBody(wallCollider);
}

void WallColliderComponent::update(sf::Time &elapsed)
{
	if (sprite)
	{
		b2Vec2 pos = Convert::box2dToWorld(wallCollider->GetPosition());
		sprite->setPosition(pos.x, pos.y);

		sprite->setRotation(wallCollider->GetAngle()*RADTODEG);
	}
}

void WallColliderComponent::draw()
{
	
}

b2Body *WallColliderComponent::getBody()
{
	return wallCollider;
}