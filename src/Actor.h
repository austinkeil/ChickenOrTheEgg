#ifndef ACTORS_INCLUDED
#define ACTORS_INCLUDED

#include "Position.h"
#include "rand.h"
#include "Bomb.h"
#include "GameObject.h"

class Actor
{
public:
	Actor(float x, float y, float size, sf::RenderWindow &w, std::vector<GameObject*> &breakable, std::vector<GameObject*> &unbreakable);
	void move(sf::Vector2f v);
	void setColor(sf::Color color);
	void setTexture(std::string texturePath);
	sf::RectangleShape &getShape();
	virtual void setPos(float x, float y);
	sf::Vector2f getPos();
	void drawMe();
	// virtual void spawn(); // randomly places actors

private:
	Position mypos;
	sf::RectangleShape m_playerShape;
	sf::Texture m_shapeTexture;
	sf::RenderWindow &m_window;
	std::vector<GameObject*> &m_breakable;
	std::vector<GameObject*> &m_unbreakable;
};

class Player : public Actor
{
public:
	Player(float x, float y, float size, sf::RenderWindow &w, std::vector<GameObject*> &breakable, std::vector<GameObject*> &unbreakable);
	void dispPower();
	void addhitpoints();
private:
	int hitpoints = 1;
	int m_power;
	std::vector<Bomb> eggs;
};

#endif //ACTORS_INCLUDED