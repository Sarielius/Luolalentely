#include "MenuState.h"
#include "Game.h"
#include "GameplayState.h"


MenuState::MenuState(Game* game) : GameState(game)
{
}


MenuState::~MenuState()
{
}

void MenuState::update(sf::Time &elapsed)
{
	game->getStateManager()->change(new GameplayState(game));
}

void MenuState::draw(sf::RenderWindow& win)
{

}
