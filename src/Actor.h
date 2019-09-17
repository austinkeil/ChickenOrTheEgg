#ifndef ACTORS_INCLUDED
#define ACTORS_INCLUDED

#include "Position.h"
#include "rand.h"
#include "Bomb.h"
#include "GameObject.h"

class Actor
{
public:
	Actor(float x, float y, float size);
	void move(float x_dist, float y_dist);
	void setColor(sf::Color color);
	void setTexture(std::string texturePath);
	sf::RectangleShape &getShape();
	virtual void setPos(float x, float y);
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
	void dispPower();
	void addhitpoints();
private:
	int hitpoints = 1;
	int m_power;
	std::vector<Bomb*> eggs;
};

#endif //ACTORS_INCLUDED
