#ifndef CAMERACOMPONENT_H
#define CAMERACOMPONENT_H
#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
#include "GameComponent.h"
#include "GameObject.h"
#include "Convert.h"


class CameraComponent : public GameComponent
{
public:
	CameraComponent(GameObject*);
	~CameraComponent();

	void update(sf::Time &elapsed);
	void draw(sf::RenderWindow &window);

	sf::View &getView();

private:
	sf::View view;
};

#endif