#include "PauseState.h"
#include "Game.h"
#include "GameplayState.h"
#include "MenuState.h"

PauseState::PauseState(Game *game) : GameState(game) 
{
	this->loadTextures();
	this->pauseBackGround.setTexture(this->textMgr.getRef("pausebackground"));
}


PauseState::~PauseState()
{
}

void PauseState::update(sf::Time &elapsed)
{
	Game *game = this->game;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		game->getStateManager()->doNextUpdate([game]()
		{
			game->getStateManager()->change(new MenuState(game));
		});

	}
}

void PauseState::draw(sf::RenderWindow &win)
{
	game->window.setView(game->window.getDefaultView());
	game->window.draw(pauseBackGround);
}

void PauseState::loadTextures()
{
	textMgr.loadTexture("pausebackground", "sprites/pause.png");
}