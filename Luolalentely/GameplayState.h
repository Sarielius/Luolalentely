#ifndef GAMEPLAYSTATE_H
#define GAMEPLAYSTATE_H
#include "GameState.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"

class GameplayState :public GameState
{
public:
	GameplayState(Game *game);
	~GameplayState();
	void update(sf::Time &elapsed);
	void draw();
	void addGameObject(GameObject*);
	void loadTextures();
private:
	std::vector<GameObject*> gameObjects;
	TextureManager textMgr;
	sf::Sprite backGround;
};
#endif