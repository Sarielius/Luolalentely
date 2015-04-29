#include "MenuState.h"
#include "Game.h"
#include "GameplayState.h"


MenuState::MenuState(Game* game) : GameState(game)
{
	this->loadTextures();
	this->menuBackGround1.setTexture(this->textMgr.getRef("start"));
	this->menuBackGround2.setTexture(this->textMgr.getRef("quit"));
	selection = 1;
}


MenuState::~MenuState()
{
}

void MenuState::update(sf::Time &elapsed)
{
	
	Game *game = this->game;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		selection = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		selection = 2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		if (selection == 1)
		{
			game->getStateManager()->doNextUpdate([game]()
			{
				game->getStateManager()->change(new GameplayState(game));
			});
		}
		else if (selection == 2)
		{
			game->window.close();
		}
	}

}

void MenuState::draw(sf::RenderWindow& win)
{
	game->window.setView(game->window.getDefaultView());

	if (selection == 1)
	{
		game->window.draw(menuBackGround1);
	}
	if (selection == 2)
	{
		game->window.draw(menuBackGround2);
	}
}

void MenuState::loadTextures()
{
	textMgr.loadTexture("start", "sprites/menu1.png");
	textMgr.loadTexture("quit", "sprites/menu2.png");
}