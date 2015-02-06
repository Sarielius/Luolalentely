#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <SFML/Graphics.hpp>

class GameState
{
public:
	GameState();
	~GameState();
	virtual void update(sf::Time &elapsed) = 0;
	virtual void draw() = 0;
};
#endif
