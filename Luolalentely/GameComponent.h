#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H
#include <SFML/Graphics.hpp>
class GameObject;
class GameComponent
{
private:
	GameObject* owner;
public:
	GameComponent(GameObject*);
	~GameComponent();
	GameObject* getOwner();
	void update(sf::Time &elapsed);
	void draw();
};

#endif