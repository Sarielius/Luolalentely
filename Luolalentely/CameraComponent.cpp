#include "CameraComponent.h"
#include "ColliderComponent.h"


CameraComponent::CameraComponent(GameObject *g) : GameComponent(g)
{
	view.setSize(sf::Vector2f(1280, 720));
}


CameraComponent::~CameraComponent()
{}

void CameraComponent::update(sf::Time &elapsed)
{}

void CameraComponent::draw(sf::RenderWindow &window)
{

}

sf::View &CameraComponent::getView()
{
	return view;
}