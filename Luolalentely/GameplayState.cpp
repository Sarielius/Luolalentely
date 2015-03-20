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

	GameObject *wall = new GameObject(game);
	wall->pushComponent(new WallColliderComponent(wall, world, sf::FloatRect(0.f, 0.f, 32.f, 32.f)));
	wall->pushComponent(new WallSpriteComponent(wall, textMgr.getRef("wall")));
	addGameObject(wall);

	this->backGround.setTexture(this->textMgr.getRef("Background"));

	//tilemap;

	//for y < height;
	//for x < width;
	//if tilemap y x == wall; 
	//create wall(y, x)
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
