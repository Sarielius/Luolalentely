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


void GameStateManager::update(sf::Time &elapsed) //Päivitetään states vektori.
{
	if (states.size() != 0)
	{
		states.back()->update(elapsed);
	}

}

void GameStateManager::draw(sf::RenderWindow& win) //Piirretään states vektorin perältä seuraava state.
{
	if (states.size() != 0)
	{
		states.back()->draw(win);
	}

}

void GameStateManager::pushState(GameState* state)
{
	states.push_back(state); //Lisää staten vektoriin
}

void GameStateManager::pop()
{
	if (states.size() != 0) //Poistaa perimmäisen staten.
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
