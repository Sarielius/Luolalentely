#ifndef PLAYERINPUTCOMPONENT
#define PLAYERINPUTCOMPONENT
#include <SFML\Graphics.hpp>
#include "GameComponent.h"

class PlayerInputComponent : public GameComponent
{
public:
	PlayerInputComponent();
	~PlayerInputComponent();	
	void update(sf::Time &elapsed);
	void draw();
};

#endif
