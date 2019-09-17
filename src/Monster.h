#ifndef MONSTERS_INCLUDED
#define MONSTERS_INCLUDED

#include "Actor.h"

class Monster : public Actor
{
public:
	Monster(float x, float y, float size, sf::RenderWindow &w);
	~Monster();
private:
};

#endif // MONSTERS_INLCLUDED
