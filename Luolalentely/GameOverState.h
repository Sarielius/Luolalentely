#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H
#include <SFML\Graphics.hpp>
#include "GameState.h"
#include "TextureManager.h"

class Game;

class GameOverState : public GameState
{
public:
	GameOverState(Game *game);
	~GameOverState();

	void update(sf::Time &elapsed);
	void draw(sf::RenderWindow &win);
	void loadTextures();

private:
	sf::Sprite gameOverScreen;
	TextureManager textMgr;
};

#endif

