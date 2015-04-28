#include "MenuState.h"
#include "Game.h"
#include "GameplayState.h"



MenuState::MenuState(Game* game) : GameState(game)
{
	this->loadTextures();
	this->menuBackGround.setTexture(this->textMgr.getRef("menubackground"));
}


MenuState::~MenuState()
{
}

void MenuState::update(sf::Time &elapsed)
{
	/*game->getStateManager()->change(new GameplayState(game));*/

	Game* game = this->game;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		game->getStateManager()->doNextUpdate([game]()
		{
			game->getStateManager()->change(new GameplayState(game));
		});
		
	}


}

void MenuState::draw(sf::RenderWindow& win)
{
	game->window.setView(game->window.getDefaultView());
	game->window.draw(menuBackGround);
}

void MenuState::loadTextures()
{
	textMgr.loadTexture("menubackground", "sprites/winner.png");
}