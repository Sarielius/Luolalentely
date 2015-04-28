#ifndef MENUSTATE_H
#define MENUSTATE_H
#include <SFML\Graphics.hpp>
#include "GameState.h"
#include "TextureManager.h"



class Game;

class MenuState : public GameState
{
public:
	MenuState(Game *game);
	~MenuState();

	void update(sf::Time &elapsed);
	void draw(sf::RenderWindow& win);
	void loadTextures();

private:
	sf::Sprite menuBackGround;
	TextureManager textMgr;
};

#endif
