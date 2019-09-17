#ifndef ACTORS_INCLUDED
#define ACTORS_INCLUDED

#include "Position.h"

class Actor
{
public:
	Actor(float x, float y, float size);
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
	Player(float x, float y, float size);
private:
};

#endif //ACTORS_INCLUDED