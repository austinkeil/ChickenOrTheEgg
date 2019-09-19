#include "Monster.h"
#include "globals.h"
#include "Actor.h"

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