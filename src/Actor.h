#ifndef ACTORS_INCLUDED
#define ACTORS_INCLUDED

#include "rand.h"
#include "Bomb.h"
#include "GameObject.h"

class Actor
{
public:
	Actor(float x, float y, float size, sf::RenderWindow &w, std::vector<GameObject*> &breakable, std::vector<GameObject*> &unbreakable);
	virtual void move(sf::Vector2f v);
	void setColor(sf::Color color);
	void setTexture(std::string texturePath);
	sf::RectangleShape &getShape();
	virtual void setPos(float x, float y);
	sf::Vector2f getPos();
	virtual void drawMe();
	virtual void spawn();

protected:
	sf::RectangleShape m_playerShape;
	sf::Texture m_shapeTexture;
	sf::RenderWindow &m_window;
	std::vector<GameObject*> &m_breakable;
	std::vector<GameObject*> &m_unbreakable;
	std::vector<Bomb*> m_droppedEggs;

};

class Player : public Actor
{
public:
	Player(float x, float y, float size, sf::RenderWindow &w, std::vector<GameObject*> &breakable, std::vector<GameObject*> &unbreakable);

	void dispPower();
	void addhitpoints();
	virtual void spawn();
	void dropEgg();
	void updateBombs();
	void explode(sf::Vector2f v);
	void explodeBreakables(sf::Vector2f v);
	void addGraphic(sf::Vector2f v, std::string filename);
private:
	int m_hitpoints;
	int m_power;
	int m_maxSize;
	std::vector<Bomb*> m_eggs;
};

#endif //ACTORS_INCLUDED