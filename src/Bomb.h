#ifndef BOMB_H
#define BOMB_H
#include "GameObject.h"
class Bomb: public GameObject{
public:
    Bomb(int x, int y, int size, sf::RenderWindow &w, std::vector<GameObject*> &pups);
    int getRange() const;//getters
    int getDamage() const;
    int getTime() const;

    void setRange(int x);//setters
    void setDamage(int x);
    void setTime(int x);
private:
    int m_range;
    int m_damage;
    int m_time;
};

#endif
