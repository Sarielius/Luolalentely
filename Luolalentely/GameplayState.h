#ifndef GAMEPLAYSTATE_H
#define GAMEPLAYSTATE_H
#include "GameState.h"
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class GameplayState :public GameState
{
public:
	GameplayState();
	~GameplayState();
	void update(sf::Time &elapsed);
	void draw();
	void addGameObject(GameObject*);
private:
	std::vector<GameObject*> gameObjects;
};
#endif