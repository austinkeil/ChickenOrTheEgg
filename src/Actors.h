#ifndef ACTORS_INCLUDED
#define ACTORS_INCLUDED

#include "Position.h"

class Actors
{
public:
	Actors(int x, int y);
	void move();
	void setColor(sf::Color color);
	void setTexture(sf::Texture);

private:
	Position mypos;
	sf::RectangleShape m_playerShape;

};

#endif //ACTORS_INCLUDED