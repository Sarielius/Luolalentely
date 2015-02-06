#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H
#include <SFML/Graphics.hpp>

class GameComponent
{
public:
	GameComponent();
	~GameComponent();
	void update(sf::Time &elapsed);
	void draw();
};

#endif