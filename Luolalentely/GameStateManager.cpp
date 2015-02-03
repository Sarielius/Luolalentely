#include "GameStateManager.h"


GameStateManager::GameStateManager()
{
}


GameStateManager::~GameStateManager()
{
}


void GameStateManager::update()
{
	if (states.size() != 0)
	{
		states.back()->update();
	}

}

void GameStateManager::draw()
{
	if (states.size() != 0)
	{
		states.back()->draw();
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
		states.erase(states.end() - 1);
	}

}

void GameStateManager::change(GameState* state)
{
	pop();
	pushState(state);
}