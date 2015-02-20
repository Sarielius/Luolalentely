#include "GameplayState.h"
#include "SpriteComponent.h"


GameplayState::GameplayState(Game *game) : GameState(game), world(b2Vec2(0.5f, 10.f))
{
	this->loadTextures();
	GameObject *gameobject = new GameObject();
	gameobject->pushComponent(new SpriteComponent(gameobject, textMgr.getRef("sprite")));
	addGameObject(gameobject);
	this->backGround.setTexture(this->textMgr.getRef("Background"));
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

void GameplayState::draw(sf::RenderWindow& win)
{
	game->window.draw(backGround);
	for (auto &object : gameObjects)
	{
		object->draw(win);
	}

}

void GameplayState::addGameObject(GameObject* gameObject)
{
	gameObjects.push_back(gameObject);
}

void GameplayState::loadTextures()
{
	textMgr.loadTexture("Background", "sprites/tausta.png");
	textMgr.loadTexture("sprite", "sprites/alus.png");
}
