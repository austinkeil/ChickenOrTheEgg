#ifndef MONSTERS_INCLUDED
#define MONSTERS_INCLUDED

#include "Actor.h"

class Monster : public Actor
{
public:
	Monster(float x, float y, float size, sf::RenderWindow &w, std::vector<GameObject*> &breakable, std::vector<GameObject*> &unbreakable);
	~Monster();

	void moveRandom();
	void setPos(float x, float y);
private:
	int m_hitpoints;
	int m_power;
	int m_pointValue;

};





#endif // MONSTERS_INLCLUDED
