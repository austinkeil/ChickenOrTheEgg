#include "Bomb.h"
using namespace std;
int Bomb::getRange() const{
    return range;
}
int Bomb::getDamage() const{
    return damage;
}
int Bomb::getTime() const{
    return time;
}
<<<<<<< HEAD

void Bomb::setRange(int x){
    range = x;
    }

void Bomb::setDamage(int x){
        damage = x;
    }

=======
void Bomb::setRange(int x){
    range = x;
    }
void Bomb::setDamage(int x){
        damage = x;
    }
>>>>>>> 928f0fb645d4d197c4b5bc75d5b5d2bc0d8e63f0
void Bomb::setTime(int x){
        time = x;
    }
