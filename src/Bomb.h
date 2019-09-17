#ifndef BOMB_H
#define BOMB_H
#include "GameObject.h"
class Bomb: public GameObject{
    int range;
    int damage;
    int time;
    public:
    int getRange() const;//getters
    int getDamage() const;
    int getTime() const;

    void setRange(int x);//setters
    void setDamage(int x);
    void setTime(int x);

}

#endif

