#ifndef ACTORS_INCLUDED
#define ACTORS_INCLUDED

#include "Position.h"

class Actor
{
public:
	Actor(int x, int y, int size);
	void move(float x_dist, float y_dist);
	void setColor(sf::Color color);
	void setTexture(std::string texturePath);
	sf::RectangleShape getShape();
	// virtual void spawn(); // randomly places actors

private:
	Position mypos;
	sf::RectangleShape m_playerShape;
	sf::Texture m_playerTexture;
};

class Player : public Actor
{
public:
	Player(int x, int y, int size);
private:
};

#endif //ACTORS_INCLUDED