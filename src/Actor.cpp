#include "Actor.h"
#include "rand.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "Game.h"
=======
#include "globals.h"
>>>>>>> 15e88880756a383890816c2310de0036549ce593
=======
<<<<<<< HEAD
#include "Game.h"
=======
#include "globals.h"
>>>>>>> origin
=======
#include "globals.h"
>>>>>>> origin
>>>>>>> master

Actor::Actor(float x, float y, float size, sf::RenderWindow &w, std::vector<GameObject*> &breakable, std::vector<GameObject*> &unbreakable)
: m_playerShape(sf::Vector2f(size, size)), m_window(w), m_breakable(breakable), m_unbreakable(unbreakable)
{
	m_playerShape.setPosition(sf::Vector2f(x, y));
}
void Actor::spawn() {

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
			if (m_breakable[i]->getPos() == newPos || m_unbreakable[i]->getPos() == newPos){
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
	for(int i = 0; i < 5;i++){
		Bomb b = Bomb(x,y,PLAYERSIZE,w, );
		eggs.push_back(b);
	}
}
void Player::spawn()
{
int playerSpawn = randInt(4);
  	switch (playerSpawn) {
    case 0:
      setPos(BLOCK_SIDE,0);
      break;
    case 1:
      setPos(14 * BLOCK_SIDE,0);
      break;
    case 2:
      setPos(0,14 * BLOCK_SIDE);
      break;
    case 3:
      setPos(14 * BLOCK_SIDE,14 * BLOCK_SIDE);
      break;
    default:
      break;
      //cry
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
	m_playerShape.setPosition(sf::Vector2f(x, y));
}