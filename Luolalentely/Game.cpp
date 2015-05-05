#include "Game.h"
#include "GameplayState.h"
#include "MenuState.h"
#include "PauseState.h"


Game::Game(int w, int h) : window(sf::VideoMode(w,h),"Cave Explorer"), paused(false) // Window size and name
{
}


Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock; 
	init(); // Initialization
	window.setFramerateLimit(60); // FPS lock
	while (window.isOpen()) // Main loop
	{
		sf::Event event; 
		while (window.pollEvent(event)) // Event polling
		{
			if (event.type == sf::Event::Closed) // Loop closes with the window
			{
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space) // "Global" pause
				{
					if (paused)
					{
						stateManager.pop();
						paused = false;
					}
					else
					{
						stateManager.pushState(new PauseState(this));
						paused = true;
					}
				}
			}
		}
		sf::Time elapsed = clock.restart(); // Resets the clock and returns the time
		window.clear(sf::Color::Black); // Clears the screen with black after each frame
		update(elapsed); // Updates everything
		draw(window); // Draws everything
		window.display(); // Displays current drawn objects
	} 
}

void Game::update(sf::Time &elapsed)
{
	stateManager.update(elapsed); 

}

void Game::draw(sf::RenderWindow& win)
{
	stateManager.draw(win);
}

void Game::init()
{
	stateManager.pushState(new MenuState(this));
}