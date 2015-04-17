#include "GameplayState.h"
#include "SpriteComponent.h"
#include "PlayerInputComponent.h"
#include "CameraComponent.h"
#include "WallColliderComponent.h"
#include "WallSpriteComponent.h"
#include <fstream>
#include <cassert>
#include <iostream>

GameplayState::GameplayState(Game *game) : GameState(game), world(b2Vec2(0.0f, 2.0f)) //Asetetaan worldin (x,y) painovoimille arvot.
{
	this->loadTextures();
	this->backGround.setTexture(this->textMgr.getRef("Background"));

	loadTileMap("maps/tilemap1.txt");

	player1 = new GameObject(game);
	player1->pushComponent(new SpriteComponent(player1, textMgr.getRef("sprite")));
	player1->pushComponent(new ColliderComponent(player1, world, sf::FloatRect(128.f, 128.f, 32.f, 32.f)));
	player1->pushComponent(new PlayerInputComponent(player1));
	player1->pushComponent(new CameraComponent(player1));
	addGameObject(player1);
	std::cout << "Player object created." << std::endl;
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
	world.Step(1.f / 60.f, 8, 3); //Päivitetään simulaatiota
	for (auto &object : gameObjects) //Päivitetään koko gameObjects vektoria ajalla.
	{
		object->update(elapsed);
	}

}

void GameplayState::draw(sf::RenderWindow& win)
{
	game->window.setView(game->window.getDefaultView());

	game->window.draw(backGround); //Piirtää taustan.

	game->window.setView(player1->getComponent<CameraComponent>()->getView());
	// TODO: vaiha view pelaajan viewiksi.

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
				GameObject *wall = new GameObject(game);
				wall->pushComponent(new WallSpriteComponent(wall, textMgr.getRef("wall"), x*64.f, y*64.f));
				wall->pushComponent(new WallColliderComponent(wall, world, sf::FloatRect(x*64.f, y*64.f, 32.f, 32.f)));

				addGameObject(wall);
			}
			else if (tile == '.')
			{
				GameObject *wall = new GameObject(game);
				wall->pushComponent(new WallSpriteComponent(wall, textMgr.getRef("empty"), x*64.f, y*64.f));
				addGameObject(wall);
			}
			
		}
	}

	file.close();
	std::cout << "Tilemap loaded." << std::endl;
}

void GameplayState::loadTextures() 
{
	textMgr.loadTexture("Background", "sprites/tausta.png"); //Backgroundille asetetaan spriteksi sprites kansiosta tausta.png
	textMgr.loadTexture("sprite", "sprites/alus.png");
	textMgr.loadTexture("wall", "sprites/wall.png");
	textMgr.loadTexture("empty", "sprites/tyhja.png");
	std::cout << "Textures loaded." << std::endl;
}
