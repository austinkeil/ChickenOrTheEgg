#include "Actor.h"

Actor::Actor(float x, float y, float size) : m_playerShape(sf::Vector2f(size, size))
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
	if (!shapeTexture.loadFromFile(texturePath)) {
		std::cout << "Failed to load texture from " << texturePath << std::endl;
	}
	m_playerShape.setTexture(&shapeTexture);
}

Player::Player(float x, float y, float size) : Actor(x, y, size)
{

}