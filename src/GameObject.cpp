#include "GameObject.h"
#include "Position.h"
#include <string>
#include "rand.h"

GameObject::GameObject(std::string name, int x, int y, sf::RenderWindow &w, std::vector<GameObject*> &pups)
: m_window(w), m_objectShape(sf::Vector2f(x,y)), m_powerUps(pups)
{
    objectPos.m_x = x;
    objectPos.m_y = y;
	m_name = name;
}

void GameObject::setColor(sf::Color color) {
	m_objectShape.setFillColor(color);
}

WallBlock::WallBlock(std::string name, int x, int y, sf::RenderWindow &w, std::vector<GameObject*> &pups)
: GameObject(name,x,y,w,pups) {}

void GameObject::setPos(int x, int y) {
	objectPos.m_x = x;
	objectPos.m_y = y;
	m_objectShape.setPosition(sf::Vector2f(x, y));
}
void GameObject::drawMe() {
	m_objectShape.setFillColor(sf::Color::White);
	std::cout << "draw me at " << m_objectShape.getPosition().x << ", " << m_objectShape.getPosition().y << std::endl;
	m_window.draw(m_objectShape);
}
std::string GameObject::getName() {
	return m_name;
}
DestructWall::DestructWall(std::string name, int x, int y, sf::RenderWindow &w, std::vector<GameObject*> &pups)
: GameObject(name,x,y,w, pups){
}
DestructWall::~DestructWall()
{
    // randomly decide whether a power up will appear or not
    int power_up = randInt(3) ;
    if(power_up==0)
    {

        //make the power up appear
    }
    else
    {
        //do nothing
    }

}

////////////////

 Worm::Worm(std::string name, int x, int y, sf::RenderWindow &w, std::vector<GameObject*> &pups)
    :GameObject(name, x, y, w, pups) {}
