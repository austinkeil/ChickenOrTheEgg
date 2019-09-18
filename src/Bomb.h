#ifndef BOMB_H
#define BOMB_H
#include "GameObject.h"
class Bomb: public GameObject {
public:
    Bomb(int x, int y, int size, sf::RenderWindow &w, std::vector<GameObject*> &pups);
    void drop(sf::Vector2f v);
    int getRange() const;//getters
    int getDamage() const;
    int getElapsed() const;
    void setRange(int x);//setters
    void setDamage(int x);
private:
    int m_range;
    int m_damage;
    sf::Clock m_clock;

};

#endif
