#ifndef ACTORS_INCLUDED
#define ACTORS_INCLUDED

#include "Position.h"

class Actors
{
public:
	Actors(int x, int y);
	virtual void moveActor(char mover)=0;  // this one sets the position based on what the user input
	virtual void spawn() = 0; // randomly places actors


private:
	Position mypos;

};

#endif //ACTORS_INCLUDED