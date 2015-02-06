#include "Game.h"
#include "GameplayState.h"


Game::Game(int w, int h) : window(sf::VideoMode(w,h),"Cave Explorer")
{
}


Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	init();
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		sf::Time elapsed = clock.restart();
		window.clear(sf::Color::Black);
		update(elapsed);
		draw();
		window.display();
	}
}

void Game::update(sf::Time &elapsed)
{
	stateManager.update(elapsed);
}

void Game::draw()
{
	stateManager.draw();
}

void Game::init()
{
	stateManager.pushState(new GameplayState);
}