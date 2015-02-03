#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "GameStateManager.h"

class Game
{
public:
	Game(int w, int h);
	~Game();
	void update();
	void draw();
	void run();
	void init();

private:
	GameStateManager stateManager;
	sf::RenderWindow window;
};
#endif
