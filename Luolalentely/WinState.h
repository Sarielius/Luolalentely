#ifndef WINSTATE_H
#define WINSTATE_H
#include <SFML\Graphics.hpp>
#include "GameState.h"
#include "TextureManager.h"


class Game;

class WinState : public GameState
{
public:
	WinState(Game *game);
	~WinState();

	void update(sf::Time &elapsed);
	void draw(sf::RenderWindow &win);
	void loadTextures();
	
private:
	sf::Sprite victoryScreen;
	TextureManager textMgr;
};

#endif
