#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <SFML/Graphics.hpp>

class Game;

class GameState
{
public:
	GameState(Game *game);
	virtual ~GameState();
	virtual void update(sf::Time &elapsed) = 0;
	virtual void draw(sf::RenderWindow& win) = 0;
protected:
	Game *game;
};
#endif
