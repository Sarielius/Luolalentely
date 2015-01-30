#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>

int main()
{
	/*sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Blue);*/

	//tehd‰‰n sprite
	sf::Texture texture;
	texture.loadFromFile("sprites/asdasd.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sf::RenderWindow window(sf::VideoMode(texture.getSize().x,texture.getSize().y), "SFML Demo");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(sprite);
		window.display();
	}
	return 0;
}
//http://www.sfml-dev.org/tutorials/2.2/
//lis‰tty spriten kokonen ikkuna