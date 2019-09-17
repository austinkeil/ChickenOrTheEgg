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
<<<<<<< HEAD
=======
    // void setRange();//setters
    // void setDamage();
    // void setTime();
>>>>>>> 928f0fb645d4d197c4b5bc75d5b5d2bc0d8e63f0

};

#endif