#include "Actor.h"
#include "rand.h"
#include "Game.h"

Actor::Actor(float x, float y, float size, sf::RenderWindow &w)
: m_playerShape(sf::Vector2f(size, size)), m_window(w)
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

void Actor::drawMe() {
	m_window.draw(m_playerShape);
}

void Actor::move(float x_dist, float y_dist) {
	m_playerShape.move(x_dist, y_dist);
	sf::sleep(sf::milliseconds(1000));
}

void Actor::move(sf::Vector2f v) {
	m_playerShape.move(v);
	// std::cout << "x: " << m_playerShape.getPosition().x << std::endl;
	// std::cout << "y: " << m_playerShape.getPosition().y << std::endl;

}

void Actor::setTexture(std::string texturePath) {
	if (!m_shapeTexture.loadFromFile(texturePath)) {
		std::cout << "Failed to load texture from " << texturePath << std::endl;
	}
	m_playerShape.setTexture(&m_shapeTexture);
}

Player::Player(float x, float y, float size, sf::RenderWindow &w) : Actor(x, y, size, w)
{
	m_power = randInt(3);
	for(int i = 0; i < 5;i++){
		Bomb b = Bomb(x,y,PLAYERSIZE,w, );
		eggs.push_back(b);
	}
}

void Player::dispPower()
{
	switch (m_power)  // depending on which power is chosen, it could call a function that will change something about the game

     {
         case 0:
		 hitpoints++;
		 //function() to display the power up to the player
			break;
         case 1:
		 for(int i =0; i < eggs.size();i++){
			eggs[i].setRange(eggs[i].getRange() + 1);
		 }
		 	break;
         case 2:
		 	max_size++;// adds the carrying capacity of bombs + 1
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