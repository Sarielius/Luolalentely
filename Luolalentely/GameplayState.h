#ifndef GAMEPLAYSTATE_H
#define GAMEPLAYSTATE_H
#include "GameState.h"
#include <SFML/Graphics.hpp>

class GameplayState :public GameState
{
public:
	GameplayState();
	~GameplayState();
	void update(sf::Time &elapsed);
	void draw();

};
#endif