#include "GameStateManager.h"
#include "TextureManager.h"


GameStateManager::GameStateManager()
{

}


GameStateManager::~GameStateManager()
{
	for (auto &state : states) 
	{
		delete state;
	}
	states.clear();
}


void GameStateManager::update(sf::Time &elapsed)
{
	if (states.size() != 0)
	{
		states.back()->update(elapsed);
	}

	for (int i = pendingActions.size() - 1; i >= 0; i--) 
	{
		pendingActions[i]();
	}

	pendingActions.clear();
}

void GameStateManager::draw(sf::RenderWindow& win) 
{
	if (states.size() != 0)
	{
		states.back()->draw(win);
	}

}

void GameStateManager::pushState(GameState* state)
{
	states.push_back(state);
}

void GameStateManager::pop()
{
	if (states.size() != 0)
	{
		delete states.back();
		states.erase(states.end() - 1);
	}

}

void GameStateManager::change(GameState* state) 
{
	pop(); 
	pushState(state);
}

void GameStateManager::doNextUpdate(std::function< void(void)> action)
{
	pendingActions.push_back(action);
}