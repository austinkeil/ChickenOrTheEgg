#ifndef BOMB_H
#define BOMB_H
#include "GameObject.h"
class Bomb: public GameObject{
<<<<<<< HEAD
    int range;
    int damage;
    int time;

    public:
=======
public:
>>>>>>> 6fa410fcf984180ddbc80e5f8294012e1d2a4c6e
    Bomb(int x, int y, int size, sf::RenderWindow &w, std::vector<GameObject*> &pups);
    int getRange() const;//getters
    int getDamage() const;
    int getTime() const;


    void setRange(int x);//setters
    void setDamage(int x);
    void setTime(int x);
<<<<<<< HEAD


=======
private:
    int m_range;
    int m_damage;
    int m_time;
>>>>>>> 6fa410fcf984180ddbc80e5f8294012e1d2a4c6e
};

#endif
