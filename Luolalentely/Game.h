#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "GameStateManager.h"

class Game
{
public:
	Game(int w, int h);
	~Game();
	void update(sf::Time &elapsed);
	void draw(sf::RenderWindow&);
	void run();
	void init();
	sf::RenderWindow window;
	GameStateManager* getStateManager()  { return &stateManager; }
private:
	GameStateManager stateManager;
	bool paused;
};
#endif
