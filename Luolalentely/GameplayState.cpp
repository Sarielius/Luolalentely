#include "GameplayState.h"
#include "SpriteComponent.h"
#include "PlayerInputComponent.h"
#include "CameraComponent.h"
#include "WallColliderComponent.h"
#include "WallSpriteComponent.h"
#include "GoalComponent.h"
#include "GoalSpriteComponent.h"
#include "HealthComponent.h"
#include <fstream>
#include <cassert>
#include <iostream>

GameplayState::GameplayState(Game *game) : GameState(game), world(b2Vec2(0.0f, 8.0f)) //Asetetaan worldin (x,y) painovoimille arvot.
{
	world.SetContactListener(&handler);
	this->loadTextures();
	this->backGround.setTexture(this->textMgr.getRef("background"));
	this->health.setTexture(this->textMgr.getRef("health"));

	loadTileMap("maps/tilemap1.txt");

	player1 = new GameObject(game);
	player1->type = TYPES::PLAYER;
	player1->pushComponent(new SpriteComponent(player1, textMgr.getRef("sprite")));
	player1->pushComponent(new ColliderComponent(player1, world, sf::FloatRect(128.f, 128.f, 32.f, 32.f)));
	player1->pushComponent(new PlayerInputComponent(player1));
	player1->pushComponent(new CameraComponent(player1));
	player1->pushComponent(new HealthComponent(player1));
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
	world.Step(1.f / 60.f, 8, 3); // World update values
	for (auto &object : gameObjects) // Updates all gameobjects
	{
		object->update(elapsed);
	}

	health.setScale(sf::Vector2f (player1->getComponent<HealthComponent>()->getHealth() /
		player1->getComponent<HealthComponent>()->getMaxHealth(), 1.0f));
}

void GameplayState::draw(sf::RenderWindow& win)
{
	

	game->window.draw(backGround); 

	game->window.setView(player1->getComponent<CameraComponent>()->getView());

	for (auto &object : gameObjects) 
	{
		object->draw(win); // Draws all gameobjects
	}

	game->window.setView(game->window.getDefaultView());

	game->window.draw(health);
}

void GameplayState::addGameObject(GameObject* gameObject)
{
	gameObjects.push_back(gameObject); 
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
				wall->type = TYPES::WALL;
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
			else if (tile == 'G')
			{
				GameObject *goal = new GameObject(game);
				goal->type = TYPES::GOAL;
				goal->pushComponent(new GoalSpriteComponent(goal, textMgr.getRef("goal"), x*64.f, y*64.f));
				goal->pushComponent(new GoalComponent(goal, world, sf::FloatRect(x*64.f, y*64.f, 32.f, 32.f)));
				addGameObject(goal);
			}
			
		}
	}

	file.close();
	std::cout << "Tilemap loaded." << std::endl;
}

void GameplayState::loadTextures() 
{
	textMgr.loadTexture("background", "sprites/tausta.png"); 
	textMgr.loadTexture("health", "sprites/health.png");
	textMgr.loadTexture("sprite", "sprites/alus.png");
	textMgr.loadTexture("wall", "sprites/wall.png");
	textMgr.loadTexture("empty", "sprites/tyhja.png");
	textMgr.loadTexture("goal", "sprites/goal.png");
	std::cout << "Textures loaded." << std::endl;
}
