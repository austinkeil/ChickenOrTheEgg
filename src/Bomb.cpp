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
void Bomb::setRange(int x){
    range = x;
    }
void Bomb::setDamage(int x){
        damage = x;
    }
void Bomb::setTime(int){
        time = x;
    }
