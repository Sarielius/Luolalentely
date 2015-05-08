#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H
#include "GameComponent.h"

class HealthComponent : public GameComponent
{
public:
	HealthComponent(GameObject*);
	~HealthComponent();
	void update(sf::Time &elapsed);
	void draw();
	float getMaxHealth();
	float getHealth();
	void setHealth(float damage);
	bool alive;
private:
	float currentHealth;
	float maximumHealth;
};

#endif
