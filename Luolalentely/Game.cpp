#include "Game.h"
#include "GameplayState.h"

Game::Game(int w, int h) : window(sf::VideoMode(w,h),"Project OSPREY")
{
}


Game::~Game()
{
}

void Game::run()
{
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

		window.clear(sf::Color::Black);
		update();
		draw();
		window.display();

	}
}

void Game::update()
{
	stateManager.update();
}

void Game::draw()
{
	stateManager.draw();
}

void Game::init()
{
	stateManager.pushState(new GameplayState);
}