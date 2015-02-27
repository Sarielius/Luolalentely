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
	virtual void update(sf::Time &elapsed) = 0;
	virtual void draw(sf::RenderWindow&);
};

#endif