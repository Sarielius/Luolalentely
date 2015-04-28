#ifndef PAUSESTATE_H
#define PAUSESTATE_H
#include <SFML\Graphics.hpp>
#include "TextureManager.h"
#include "GameState.h"

class Game;

class PauseState : public GameState
{
public:
	PauseState(Game *game);
	~PauseState();

	void update(sf::Time &elapsed);
	void draw(sf::RenderWindow &win);
	void loadTextures();

private:
	sf::Sprite pauseBackGround;
	TextureManager textMgr;
};

#endif

