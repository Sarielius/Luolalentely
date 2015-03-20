#include "ColliderComponent.h"
#include "GameObject.h"
#include "Convert.h"

ColliderComponent::ColliderComponent(GameObject* g, b2World& world, sf::FloatRect dimensions) : GameComponent(g), world(world)
{
	b2BodyDef def; //Luodaan uusi bodyDefinition.
	def.fixedRotation = false; //True arvolla objekti ei pyöri voimien vaikutuksesta.
	def.type = b2_dynamicBody; //Muutetaan tyyppi default staticista dynaamiseksi.
	def.angularDamping = 5.f; //Asetetaan kulmavaimennukselle arvo. Objekti ei jää pyörimään.
	def.linearDamping = 0.2f; //Asetetaan nopeusvaimennukselle arvo. 
	def.position = Convert::worldToBox2d(dimensions.left, dimensions.top); 
	collider = world.CreateBody(&def); //Luodaan worldiin collider def:in perusteella.
	b2PolygonShape Shape;
	
	Shape.SetAsBox(Convert::worldToBox2d(dimensions.width /2.f ), Convert::worldToBox2d(dimensions.height / 2.f));
	
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.1f;
	FixtureDef.friction = 0.1f;
	//FixtureDef.restitution = 0.f;

	FixtureDef.shape = &Shape;
	collider->CreateFixture(&FixtureDef);
}


ColliderComponent::~ColliderComponent()
{
	world.DestroyBody(collider);
}

void ColliderComponent::update(sf::Time &elapsed)
{
	

}
void ColliderComponent::draw()
{


}

b2Body* ColliderComponent::getBody()
{
	return collider;
}

//	ColliderComponent* asd = g->getComponent<ColliderComponent>();