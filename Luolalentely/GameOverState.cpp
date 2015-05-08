#include "GameOverState.h"
#include "Game.h"
#include "MenuState.h"
#include "GameplayState.h"

GameOverState::GameOverState(Game *game) : GameState(game)
{
	this->loadTextures();
	this->gameOverScreen.setTexture(this->textMgr.getRef("gameover"));
}


GameOverState::~GameOverState()
{
}

void GameOverState::update(sf::Time &elapsed)
{
	Game *game = this->game;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		game->getStateManager()->doNextUpdate([game]()
		{
			game->getStateManager()->change(new MenuState(game));
		});
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		game->getStateManager()->doNextUpdate([game]()
		{
			game->getStateManager()->change(new GameplayState(game));
		});

	}
}

void GameOverState::draw(sf::RenderWindow &win)
{
	game->window.setView(game->window.getDefaultView());
	game->window.draw(gameOverScreen);
}

void GameOverState::loadTextures()
{
	textMgr.loadTexture("gameover", "sprites/gameover.png");
}