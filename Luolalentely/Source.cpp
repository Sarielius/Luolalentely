#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Demo");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Blue);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;
}
//http://www.sfml-dev.org/tutorials/2.2/