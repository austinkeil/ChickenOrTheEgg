#include "Actor.h"
#include "rand.h"

Actor::Actor(float x, float y, float size) : m_playerShape(sf::Vector2f(size, size))
{
	mypos.m_x = x;
	mypos.m_y = y;
}

void Actor::setColor(sf::Color color) {
	m_playerShape.setFillColor(color);
}

sf::RectangleShape &Actor::getShape() {
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
	m_power = randInt(3);
}

void Player::dispPower()
{
	switch (m_power)  // depending on which power is chosen, it could call a function that will change something about the game

     {
         case 0:
			addhitpoints();
			break;
         case 1:
		 	break;
         //increase bomb range: this depends on what the bomb range is orignally (check bomb class) and increase it
         case 2:
		 	//int myrange = eggs.getRange();
		 	//eggs.setRange(myrange + 1);
			 break;

		default:
			break;
	 }
}

void Player :: addhitpoints()
{
	hitpoints+=1;
}
void Actor::setPos(float x, float y)
{
	mypos.m_x = x;
	mypos.m_y = y;
}
