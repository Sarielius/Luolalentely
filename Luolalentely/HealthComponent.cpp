#include "HealthComponent.h"


HealthComponent::HealthComponent(GameObject *g) : GameComponent(g)
{
	maximumHealth = 1.0f;
	currentHealth = maximumHealth;
}


HealthComponent::~HealthComponent()
{
}

void HealthComponent::draw()
{
}

void HealthComponent::update(sf::Time &elapsed)
{
}

float HealthComponent::getMaxHealth()
{
	return maximumHealth;
}

float HealthComponent::getHealth()
{
	return currentHealth;
}

void HealthComponent::setHealth(float damage)
{
	currentHealth = currentHealth + damage;
}