#include "Game.h"
#include "GameplayState.h"
#include "MenuState.h"
#include "PauseState.h"


Game::Game(int w, int h) : window(sf::VideoMode(w,h),"Cave Explorer"), paused(false) // Asettaa ikkunan kooksi saadut arvot ja laittaa kivan nimen yl‰kulmaan
{
}


Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock; // Tehd‰‰n kello
	init(); // K‰ynnist‰‰ pelin luomalla gameplaystaten
	/*window.setFramerateLimit(60);*/ // FPS lock
	while (window.isOpen()) // Looppi pyˆrii kun ikkuna on auki
	{
		sf::Event event; // Tehd‰‰n eventti
		while (window.pollEvent(event)) // Tarkistaa eventin tyyppi‰ koko ajan.
		{
			if (event.type == sf::Event::Closed) // Jos ikkuna suljetaan, ohjelma sulkeutuu
				window.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
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
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
			}
		}
		sf::Time elapsed = clock.restart(); // clock.restart() palauttaa kellon arvon eli ajan ja resetoi sen.
		window.clear(sf::Color::Black); // Ruutu k‰y joka framen v‰liss‰ mustana, eli paint it black edellisen framen p‰‰lle.
		update(elapsed); // P‰ivitet‰‰n ajalla.
		draw(window); // Piirt‰‰ kaiken ikkunaan.
		window.display(); // N‰ytt‰‰ k‰ytt‰j‰lle ikkunassa stuffii.
	} // Rinse and repeat kunnes ikkuna suljetaan.
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