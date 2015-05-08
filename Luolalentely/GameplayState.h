#ifndef GAMEPLAYSTATE_H
#define GAMEPLAYSTATE_H
#include <Box2D\Box2D.h>
#include "GameState.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "CollisionHandler.h"

class GameplayState :public GameState
{
public:
	GameplayState(Game *game);
	~GameplayState();
	void update(sf::Time &elapsed);
	void draw(sf::RenderWindow &win);
	void addGameObject(GameObject*);
	void loadTextures();
	void loadTileMap(const std::string &path);
private:
	CollisionHandler handler;
	b2World world;
	std::vector<GameObject*> gameObjects;
	TextureManager textMgr;
	sf::Sprite backGround;
	sf::Sprite health;
	GameObject *player;
};
#endif