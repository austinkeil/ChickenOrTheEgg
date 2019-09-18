#include "Bomb.h"
using namespace std;

Bomb::Bomb(int x, int y, int size, sf::RenderWindow &w, std::vector<GameObject*> &pups)
: GameObject(x,y,size,w,pups)
{
    m_exploded = false;
}
void Bomb::drop(sf::Vector2f v) {
    m_objectShape.setPosition(v);
    m_clock.restart();
    cout << "Bomb::drop() at " << v.x
    << ", " << v.y << endl;
    drawMe();
}
bool Bomb::isExploded() {
    return m_exploded;
}
void Bomb::setExploded(bool b) {
    m_exploded = b;
}
int Bomb::getRange() const{
    return m_range;
}
int Bomb::getDamage() const{
    return m_damage;
}
int Bomb::getElapsed() const{
    return m_clock.getElapsedTime().asSeconds();
}
void Bomb::drawMe() {
    if (!m_exploded) {
        m_window.draw(m_objectShape);
    }
}

void Bomb::setRange(int x){
    m_range = x;
    }

void Bomb::setDamage(int x){
    m_damage = x;
}