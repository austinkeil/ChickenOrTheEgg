#include "Actor.h"
#include "rand.h"
#include "Game.h"
#include "Bomb.h"
#include "ExplosionGraphic.h"
#include "globals.h"

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
			if (m_breakable[i]->getPos() == newPos || m_unbreakable[i]->getPos() == newPos){
				validMove = false;
				break;
			}
		}
		if (validMove) {
			for (int i = 0; i < static_cast<int>(m_droppedEggs.size()); i++) {
				if (m_droppedEggs[i]->getPos() == newPos) {
					validMove = false;
					break;
				}
			}
			if (validMove)
				m_playerShape.move(v);
		}
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

Monster :: Monster(float x, float y, float size, sf::RenderWindow &w, std::vector<GameObject*> &breakable, std::vector<GameObject*> &unbreakable)
: Actor(x, y, size, w, breakable, unbreakable)
{
	m_hitpoints = 1;
	m_pointValue = 97;
	m_power = 1;
}

void Monster::setPos(float x, float y)
{
	m_playerShape.setPosition(sf::Vector2f(x, y));
}

void Monster::moveRandom()
{
	sf::Vector2f v;
	int movement = randInt(4);
	switch (movement)
	{
	case 0:
		v.x = 0;
		v.y = BLOCK_SIDE;
		break;
	case 1:
		v.x = BLOCK_SIDE;
		v.y = 0;
		break;
	case 2:
		v.x = -1 * BLOCK_SIDE;
		v.y = 0;
		break;
	case 3:
		v.x = 0;
		v.y = -1 * BLOCK_SIDE;
		break;
	default:
		break;
	}

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
}

Player::Player(float x, float y, float size, sf::RenderWindow &w, std::vector<GameObject*> &breakable, std::vector<GameObject*> &unbreakable, std::vector<Monster*> &enemies)
: Actor(x, y, size, w, breakable, unbreakable), m_enemies(enemies)
{
	m_power = randInt(3);
	for(int i = 0; i < BOMB_COUNT;i++){
		Bomb *b = new Bomb(x,y,PLAYERSIZE,w, breakable);
		b->setColor(sf::Color::White);
		b->setTexture("content/tnt.png");
		m_eggs.push_back(b);
	}
}
void Player::dropEgg()
{
	if (m_eggs.size() > 0) {
		Bomb *b = m_eggs[static_cast<int>(m_eggs.size()) - 1];
		m_eggs.pop_back();
		b->drop(getPos());
		m_droppedEggs.push_back(b);
	}
}
void Player::updateBombs()
{
	auto it = m_droppedEggs.begin();
	while (it != m_droppedEggs.end()) {
		if ((*it)->getElapsed() >= BOMB_TIME) {
			(*it)->setExploded(true);
			if ((*it)->getElapsed() >= EXPLODE_TIME) {
				std::cout << "clearing explosion at " << (*it)->getPos().x << ", " << (*it)->getPos().y << std::endl;
				it = m_droppedEggs.erase(it);
			} else {
				sf::Vector2f v = (*it)->getPos();
				explode(v);
				++it;
				drawMe();
			}
		} else {
			(*it)->drawMe();
			++it;
			drawMe();
		}
	}
}
void Player::explodeBreakables(sf::Vector2f v){
	auto it = m_breakable.begin();
		while (it != m_breakable.end()) {
			if ((*it)->getPos() == v) {
				std::cout << "erasing" << std::endl;
				it = m_breakable.erase(it);
			} else {
				++it;
			}
		}
}
void Player::explodeZombies(sf::Vector2f v) {
	auto it = m_enemies.begin();
		while (it != m_enemies.end()) {
			if ((*it)->getPos() == v) {
				std::cout << "erasing" << std::endl;
				it = m_enemies.erase(it);
			} else {
				++it;
			}
		}
}
void Player::addGraphic(sf::Vector2f v, std::string filename) {
	sf::RectangleShape r(sf::Vector2f(BLOCK_SIDE, BLOCK_SIDE));
	r.setPosition(v);
	sf::Texture t;
	if (!t.loadFromFile(filename)) {
		std::cout << "Failed to load texture from " << filename << std::endl;
	}
	r.setTexture(&t);
	m_playerShape.setTexture(&m_shapeTexture);
	m_window.draw(r);
}

void Player::explode(sf::Vector2f v) {
	sf::Vector2f left = v + sf::Vector2f(-BLOCK_SIDE, 0);
	sf::Vector2f right = v + sf::Vector2f(BLOCK_SIDE, 0);
	sf::Vector2f up = v + sf::Vector2f(0, -BLOCK_SIDE);
	sf::Vector2f down = v + sf::Vector2f(0, BLOCK_SIDE);
	ExplosionGraphic(v, "content/centerExplosion.png", m_window);
	if (left.x >= 0) {
		ExplosionGraphic(left, "content/leftExplosion.png", m_window);
		explodeBreakables(left);
		explodeZombies(left);
	}
	if (right.x <= BOARD_WIDTH - BLOCK_SIDE) {
		ExplosionGraphic(right, "content/rightExplosion.png", m_window);
		explodeBreakables(right);
		explodeZombies(right);

	}
	if (up.y >= 0) {
		ExplosionGraphic(up, "content/topExplosion.png", m_window);
		explodeBreakables(up);
		explodeZombies(up);
	}
	if (down.y <= BOARD_HEIGHT - BLOCK_SIDE) {
		ExplosionGraphic(down, "content/bottomExplosion.png", m_window);
		explodeBreakables(down);
		explodeZombies(down);
	}
	std::cout << std::endl;
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
		 m_hitpoints++;
		 //function() to display the power up to the player
			break;
         case 1:
		 for(int i = 0; i < static_cast<int>(m_eggs.size());i++){
			m_eggs[i]->setDamage(m_eggs[i]->getDamage() + 1);
		 }
		 	break;
         case 2:
		 	m_maxSize++;// adds the carrying capacity of bombs + 1
			break;

		default:
			break;
	 }
}

void Player :: addhitpoints()
{
	m_hitpoints+=1;
}
void Actor::setPos(float x, float y)
{
	m_playerShape.setPosition(sf::Vector2f(x, y));
}