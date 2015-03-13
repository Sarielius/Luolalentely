#include "GameplayState.h"
#include "SpriteComponent.h"
#include "PlayerInputComponent.h"

GameplayState::GameplayState(Game *game) : GameState(game), world(b2Vec2(0.0f, 2.0f))
{
	this->loadTextures();
	GameObject *gameobject = new GameObject();
	gameobject->pushComponent(new ColliderComponent(gameobject, world, sf::FloatRect(0.f, 0.f, 32.f, 32.f)));
	gameobject->pushComponent(new PlayerInputComponent(gameobject));
	gameobject->pushComponent(new SpriteComponent(gameobject, textMgr.getRef("sprite")));
	addGameObject(gameobject);
	//float32 angle = 
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
	world.Step(1.f / 60.f, 8, 30);
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
