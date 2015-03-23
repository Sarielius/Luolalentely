#include "GameplayState.h"
#include "SpriteComponent.h"
#include "PlayerInputComponent.h"
#include "WallColliderComponent.h"
#include "WallSpriteComponent.h"

GameplayState::GameplayState(Game *game) : GameState(game), world(b2Vec2(0.0f, 2.0f)) //Asetetaan worldin (x,y) painovoimille arvot.
{
	this->loadTextures();

	GameObject *alus = new GameObject(game);
	alus->pushComponent(new ColliderComponent(alus, world, sf::FloatRect(0.f, 0.f, 32.f, 32.f)));
	alus->pushComponent(new PlayerInputComponent(alus));
	alus->pushComponent(new SpriteComponent(alus, textMgr.getRef("sprite")));
	addGameObject(alus);

	//GameObject *wall = new GameObject(game);
	//wall->pushComponent(new WallColliderComponent(wall, world, sf::FloatRect(0.f, 0.f, 32.f, 32.f)));
	//wall->pushComponent(new WallSpriteComponent(wall, textMgr.getRef("wall")));
	//addGameObject(wall);

	this->backGround.setTexture(this->textMgr.getRef("Background"));

	size_t height = 100;
	size_t width = 100;

	for (size_t y = 0; y < height; y++)
	{
		for (size_t x = 0; x < width; x++)
		{
			GameObject *newWall = new GameObject(game);
			newWall->pushComponent(new WallColliderComponent(newWall, world, sf::FloatRect(x*64.f, y*64.f, 32.f, 32.f)));
			newWall->pushComponent(new WallSpriteComponent(newWall, textMgr.getRef("wall")));
			addGameObject(newWall);
		}
	}
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
	world.Step(1.f / 60.f, 8, 30); //P‰ivitet‰‰n simulaatiota
	for (auto &object : gameObjects) //P‰ivitet‰‰n koko gameObjects vektoria ajalla.
	{
		object->update(elapsed);
	}

}

void GameplayState::draw(sf::RenderWindow& win)
{
	game->window.draw(backGround); //Piirt‰‰ taustan.
	for (auto &object : gameObjects) //K‰y gameObjects vectorin l‰pi ja piirt‰‰ sen sis‰llˆn.
	{
		object->draw(win); //K‰ytt‰‰ gameObjectin omaa draw()ia.
	}

}

void GameplayState::addGameObject(GameObject* gameObject)
{
	gameObjects.push_back(gameObject); //Lis‰‰ gameObjects vektoriin gameObjekteja.
}

void GameplayState::loadTextures() 
{
	textMgr.loadTexture("Background", "sprites/tausta.png"); //Backgroundille asetetaan spriteksi sprites kansiosta tausta.png
	textMgr.loadTexture("sprite", "sprites/alus.png");
	textMgr.loadTexture("wall", "sprites/wall.png");
}
