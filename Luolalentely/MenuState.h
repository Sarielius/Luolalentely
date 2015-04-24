#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "GameState.h"

class Game;

class MenuState : public GameState
{
public:
	MenuState(Game *game);
	~MenuState();

	void update(sf::Time &elapsed);
	void draw(sf::RenderWindow& win);

	Game* game;
};

#endif
