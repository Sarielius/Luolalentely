#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H
#include <vector>
#include "GameState.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>
#include <functional>

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

	void doNextUpdate(std::function< void(void)> action);

private:
	std::vector<std::function<void(void)>> pendingActions;
	std::vector<GameState*> states;
};
#endif
