#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H
#include <vector>
#include "GameState.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>

class GameStateManager
{
public:
	GameStateManager();
	~GameStateManager();
	void pushState(GameState*);
	void pop();
	void update(sf::Time &elapsed);
	void draw(sf::RenderWindow&);
	void change(GameState*);


private:
	std::vector<GameState*> states;
};
#endif
