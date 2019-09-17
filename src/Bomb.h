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

<<<<<<< HEAD
    void setRange(int x);//setters
    void setDamage(int x);
    void setTime(int x);
=======
    // void setRange();//setters
    // void setDamage();
    // void setTime();
>>>>>>> 7c9c45c2cf8362458766bce377c3e759f0d349e8

};

#endif