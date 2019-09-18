#include "Bomb.h"
using namespace std;

Bomb::Bomb(int x, int y, int size, sf::RenderWindow &w, std::vector<GameObject*> &pups)
:GameObject(x,y,size,w,pups){
    range = 1;
    damage = 1;
    time = 5;
}
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
void Bomb::setTime(int x){
        time = x;
    }
