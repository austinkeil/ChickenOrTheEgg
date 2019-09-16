#include "Actor.h"

Actor::Actor(int x, int y, int size) : m_playerShape(sf::Vector2f(size, size))
{
	mypos.m_x = x;
	mypos.m_y = y;
}

void Actor::setColor(sf::Color color) {
	m_playerShape.setFillColor(color);
}

sf::RectangleShape Actor::getShape() {
	return m_playerShape;
}


void Actor::move(float x_dist, float y_dist) {
	m_playerShape.move(x_dist, y_dist);
}

void Actor::setTexture(std::string texturePath) {
	sf::Texture shapeTexture;
	shapeTexture.loadFromFile(texturePath);
	m_playerShape.setTexture(&shapeTexture);
}

Player::Player(int x, int y, int size) : Actor(x, y, size)
{

}