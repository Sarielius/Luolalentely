#ifndef TILEMAP_H
#define TILEMAP_H
#include <SFML\Graphics.hpp>
#include "GameObject.h"

class TileMap
{
public:
	TileMap();
	~TileMap();
	void draw(sf::RenderWindow &window);
private:
};

#endif
