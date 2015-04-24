#include "ColliderComponent.h"
#include "SpriteComponent.h"
#include "GameObject.h"
#include "Convert.h"
#define RADTODEG 57.295779513082320876f

ColliderComponent::ColliderComponent(GameObject* g, b2World& world, sf::FloatRect dimensions) : GameComponent(g), world(world), sprite(nullptr)
{
	SpriteComponent* temp = getOwner()->getComponent<SpriteComponent>();
	if (temp)
	{
		sprite = temp->getSprite();
	}

	b2BodyDef def; //Luodaan uusi bodyDefinition.
	def.fixedRotation = false; //True arvolla objekti ei pyöri voimien vaikutuksesta.
	def.type = b2_dynamicBody; //Muutetaan tyyppi default staticista dynaamiseksi.
	def.angularDamping = 5.f; //Asetetaan kulmavaimennukselle arvo. Objekti ei jää pyörimään.
	def.linearDamping = 0.2f; //Asetetaan nopeusvaimennukselle arvo. 
	def.position = Convert::worldToBox2d(dimensions.left, dimensions.top); 
	collider = world.CreateBody(&def); //Luodaan worldiin collider def:in perusteella.

	collider->SetUserData(g);
	
	b2Vec2 vertices[3];

	vertices[0].Set(0.0f, -1.0f * Convert::worldToBox2d(dimensions.height));

	vertices[1].Set(0.8f * Convert::worldToBox2d(dimensions.width), 0.8f * Convert::worldToBox2d(dimensions.height));

	vertices[2].Set(-0.8f * Convert::worldToBox2d(dimensions.width), 0.8f * Convert::worldToBox2d(dimensions.height));

	int32 count = 3;
	
	b2PolygonShape Shape;

	Shape.Set(vertices, count);
	

	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.1f;
	FixtureDef.friction = 0.1f;
	FixtureDef.restitution = 0.2f;

	FixtureDef.shape = &Shape;
	collider->CreateFixture(&FixtureDef);
}


ColliderComponent::~ColliderComponent()
{
	world.DestroyBody(collider);
}

void ColliderComponent::update(sf::Time &elapsed)
{
	if (sprite)
	{
		b2Vec2 pos = Convert::box2dToWorld(collider->GetPosition());
		sprite->setPosition(pos.x, pos.y);

		sprite->setRotation(collider->GetAngle()*RADTODEG);
	}
}

void ColliderComponent::draw()
{

}

b2Body* ColliderComponent::getBody()
{
	return collider;
}
