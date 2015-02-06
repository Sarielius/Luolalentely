#include "GameplayState.h"



GameplayState::GameplayState()
{
}


GameplayState::~GameplayState()
{
	for (auto &object : gameObjects)
	{
		delete object;
	}
	gameObjects.clear();
}

void GameplayState::update(sf::Time &elapsed)
{
	for (auto &object : gameObjects)
	{
		object->update(elapsed);
	}

}

void GameplayState::draw()
{
	for (auto &object : gameObjects)
	{
		object->draw();
	}

}

void GameplayState::addGameObject(GameObject* gameObject)
{
	gameObjects.push_back(gameObject);
}