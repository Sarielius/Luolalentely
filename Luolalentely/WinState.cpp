#include "WinState.h"
#include "Game.h"
#include "GameplayState.h"
#include "MenuState.h"

WinState::WinState(Game *game) : GameState(game)
{
	this->loadTextures();
	this->victoryScreen.setTexture(this->textMgr.getRef("victoryscreen"));
}


WinState::~WinState()
{
}

void WinState::update(sf::Time &elapsed)
{
	Game *game = this->game;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		game->getStateManager()->doNextUpdate([game]()
		{
			game->getStateManager()->change(new MenuState(game));
		});

	}
}

void WinState::draw(sf::RenderWindow &win)
{
	game->window.setView(game->window.getDefaultView());
	game->window.draw(victoryScreen);
}

void WinState::loadTextures()
{
	textMgr.loadTexture("victoryscreen", "sprites/winner.png");
}