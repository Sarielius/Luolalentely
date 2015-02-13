#include "ColliderComponent.h"
#include "GameObject.h"

ColliderComponent::ColliderComponent(GameObject* g) : GameComponent(g)
{
	ColliderComponent* asd = g->getComponent<ColliderComponent>();
}


ColliderComponent::~ColliderComponent()
{
}

void ColliderComponent::update(sf::Time &elapsed)
{


}
void ColliderComponent::draw()
{


}
