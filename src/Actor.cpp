#include "Actor.h"
#include "rand.h"
#include "globals.h"

Actor::Actor(float x, float y, float size, sf::RenderWindow &w, std::vector<GameObject*> &breakable, std::vector<GameObject*> &unbreakable)
: m_playerShape(sf::Vector2f(size, size)), m_window(w), m_breakable(breakable), m_unbreakable(unbreakable)
{
	m_playerShape.setPosition(sf::Vector2f(x, y));
	(void)m_unbreakable;
}

void Actor::setColor(sf::Color color) {
	m_playerShape.setFillColor(color);
}

sf::RectangleShape &Actor::getShape() {
	return m_playerShape;
}

void Actor::drawMe() {
	m_window.draw(m_playerShape);
}

sf::Vector2f Actor::getPos() {
	return m_playerShape.getPosition();
}

void Actor::move(sf::Vector2f v) {
	sf::Vector2f newPos = m_playerShape.getPosition() + v;
	bool validMove = true;
	if (newPos.x >= 0 && newPos.x <= BOARD_WIDTH - BLOCK_SIDE && newPos.y >= 0 && newPos.y <= BOARD_WIDTH - BLOCK_SIDE)
	{
		for (int i = 0; i < NUMBER_OF_BLOCKS; i++) {
			// std::cout << "checking if player pos (" << newPos.x << ", " << newPos.y
			// << ") equals block pos (" << m_breakable[i]->getPos().x << ", " << m_breakable[i]->getPos().y << ")" << std::endl;
			if (m_breakable[i]->getPos() == newPos){
				validMove = false;
				break;
			}
		}
		if (validMove)
			m_playerShape.move(v);
	}
	// std::cout << "x: " << m_playerShape.getPosition().x << std::endl;
	// std::cout << "y: " << m_playerShape.getPosition().y << std::endl;

}

void Actor::setTexture(std::string texturePath) {
	if (!m_shapeTexture.loadFromFile(texturePath)) {
		std::cout << "Failed to load texture from " << texturePath << std::endl;
	}
	m_playerShape.setTexture(&m_shapeTexture);
}

Player::Player(float x, float y, float size, sf::RenderWindow &w, std::vector<GameObject*> &breakable, std::vector<GameObject*> &unbreakable)
: Actor(x, y, size, w, breakable, unbreakable)
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
	m_playerShape.setPosition(sf::Vector2f(x, y));
}