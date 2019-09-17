#ifndef MONSTERS_INCLUDED
#define MONSTERS_INCLUDED

#include "Position.h"
#include "Actor.h"

class Monster
{
public:
	Monster(int x, int y, int size);
private:
};

#endif // monsters included


/*
in the first level, all monsters are foxes and they can take one hit. 
as levels progress, we can have some foxes and some coyotes
coyotes can take a hit and then turn into a fox. (if a fox takes a hit it dies)

*/