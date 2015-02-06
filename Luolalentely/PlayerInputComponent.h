#ifndef PLAYERINPUTCOMPONENT
#define PLAYERINPUTCOMPONENT
#include <SFML\Graphics.hpp>

class PlayerInputComponent
{
public:
	PlayerInputComponent();
	~PlayerInputComponent();	
	void update(sf::Time &elapsed);
	void draw();
};

#endif
