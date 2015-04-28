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


void GameStateManager::update(sf::Time &elapsed) //P‰ivitet‰‰n states vektori.
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

void GameStateManager::draw(sf::RenderWindow& win) //Piirret‰‰n states vektorin per‰lt‰ seuraava state.
{
	if (states.size() != 0)
	{
		states.back()->draw(win);
	}

}

void GameStateManager::pushState(GameState* state)
{
	states.push_back(state); //Lis‰‰ staten vektoriin
}

void GameStateManager::pop()
{
	if (states.size() != 0) //Poistaa perimm‰isen staten.
	{
		delete states.back();
		states.erase(states.end() - 1);
	}

}

void GameStateManager::change(GameState* state) //Poistaa staten ja "vaihtaa" tilalle toisen staten.
{
	pop(); 
	pushState(state);
}

void GameStateManager::doNextUpdate(std::function< void(void)> action)
{
	pendingActions.push_back(action);
}