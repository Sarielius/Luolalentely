#include "GameplayState.h"
#include "SpriteComponent.h"
#include "PlayerInputComponent.h"
#include "WallColliderComponent.h"
#include "WallSpriteComponent.h"
#include <fstream>
#include <cassert>


GameplayState::GameplayState(Game *game) : GameState(game), world(b2Vec2(0.0f, 2.0f)) //Asetetaan worldin (x,y) painovoimille arvot.
{
	this->loadTextures();

	GameObject *alus = new GameObject(game);
	alus->pushComponent(new ColliderComponent(alus, world, sf::FloatRect(128.f, 128.f, 32.f, 32.f)));
	alus->pushComponent(new PlayerInputComponent(alus));
	alus->pushComponent(new SpriteComponent(alus, textMgr.getRef("sprite")));
	addGameObject(alus);

	this->backGround.setTexture(this->textMgr.getRef("Background"));

	loadTileMap("maps/tilemap1.txt");

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
	world.Step(1.f / 60.f, 8, 30); //Päivitetään simulaatiota
	for (auto &object : gameObjects) //Päivitetään koko gameObjects vektoria ajalla.
	{
		object->update(elapsed);
	}

}

void GameplayState::draw(sf::RenderWindow& win)
{
	game->window.draw(backGround); //Piirtää taustan.
	for (auto &object : gameObjects) //Käy gameObjects vectorin läpi ja piirtää sen sisällön.
	{
		object->draw(win); //Käyttää gameObjectin omaa draw()ia.
	}

}

void GameplayState::addGameObject(GameObject* gameObject)
{
	gameObjects.push_back(gameObject); //Lisää gameObjects vektoriin gameObjekteja.
}

void GameplayState::loadTileMap(const std::string &path)
{
	std::ifstream file(path);

	assert(file.is_open());

	size_t width;
	size_t height;

	file >> width >> std::ws;
	file >> height >> std::ws;

	for (size_t y = 0; y < height; y++)
	{
		for (size_t x = 0; x < width; x++)
		{
			char tile;
			file >> tile >> std::ws;

			if (tile == 'X')
			{
				GameObject* wall = new GameObject(game);
				wall->pushComponent(new WallColliderComponent(wall, world, sf::FloatRect(x*64.f, y*64.f, 32.f, 32.f)));
				wall->pushComponent(new WallSpriteComponent(wall, textMgr.getRef("wall")));

				addGameObject(wall);
			}
		}
	}

	file.close();
}

void GameplayState::loadTextures() 
{
	textMgr.loadTexture("Background", "sprites/tausta.png"); //Backgroundille asetetaan spriteksi sprites kansiosta tausta.png
	textMgr.loadTexture("sprite", "sprites/alus.png");
	textMgr.loadTexture("wall", "sprites/wall.png");
}
