#include "CameraComponent.h"
#include "ColliderComponent.h"
#include "SpriteComponent.h"
#include <iostream>


CameraComponent::CameraComponent(GameObject *g) : GameComponent(g)
{
	view.setSize(sf::Vector2f(1280, 720));
}


CameraComponent::~CameraComponent()
{}

void CameraComponent::update(sf::Time &elapsed)
{
	b2Vec2 pos =  Convert::box2dToWorld(getOwner()->getComponent<ColliderComponent>()->getBody()->GetPosition());
	/*sf::Vector2f pos = getOwner()->getComponent<SpriteComponent>()->getSprite()->getPosition();*/
	view.setCenter(pos.x, pos.y);
}

void CameraComponent::draw(sf::RenderWindow &window)
{
	window.setView(view);
}

sf::View &CameraComponent::getView()
{
	return view;
}