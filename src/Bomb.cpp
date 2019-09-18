#include "Bomb.h"
using namespace std;

Bomb::Bomb(int x, int y, int size, sf::RenderWindow &w, std::vector<GameObject*> &pups)
: GameObject(x,y,size,w,pups)
{

}
void Bomb::drop(sf::Vector2f v) {
    m_objectShape.setPosition(v);
    cout << "Bomb::drop() at " << v.x
    << ", " << v.y << endl;
    drawMe();
}
int Bomb::getRange() const{
    return m_range;
}
int Bomb::getDamage() const{
    return m_damage;
}
int Bomb::getTime() const{
    return m_time;
}

void Bomb::setRange(int x){
    m_range = x;
    }

void Bomb::setDamage(int x){
    m_damage = x;
}
void Bomb::setTime(int x){
    m_time = x;
}