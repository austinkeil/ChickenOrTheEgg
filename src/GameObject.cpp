#include "GameObject.h"
#include "Position.h"
#include <string>
#include "rand.h"

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
GameObject::GameObject(){}
GameObject::GameObject(std::string name, int x, int y, sf::RenderWindow &w)
: m_window(w)
=======
GameObject::GameObject(std::string name, int x, int y, sf::RenderWindow &w, std::vector<GameObject*> &pups)
: m_window(w), m_powerUps(pups)
>>>>>>> 55c2895eeb5c466fa6d2f3c84c3a7c76360c75dc
=======
GameObject::GameObject(std::string name, int x, int y, sf::RenderWindow &w, std::vector<GameObject*> &pups)
: m_window(w), m_powerUps(pups)
>>>>>>> 6a07d42fcf0fd63a491985311d1b99412c9383ef
=======
GameObject::GameObject(int x, int y, int size, sf::RenderWindow &w, std::vector<GameObject*> &pups)
: m_window(w), m_objectShape(sf::Vector2f(size,size)), m_powerUps(pups)
>>>>>>> d1c6938b6653a87a649367193449da31055b6e11
{
    objectPos.m_x = x;
    objectPos.m_y = y;
}

void GameObject::setColor(sf::Color color) {
	m_objectShape.setFillColor(color);
}

WallBlock::WallBlock(int x, int y, int size, sf::RenderWindow &w, std::vector<GameObject*> &pups)
: GameObject(x,y, size, w,pups) {}

void GameObject::setPos(int x, int y) {
	objectPos.m_x = x;
	objectPos.m_y = y;
	m_objectShape.setPosition(sf::Vector2f(x, y));
}
void GameObject::drawMe() {
	// std::cout << "draw me at " << m_objectShape.getPosition().x << ", " << m_objectShape.getPosition().y << std::endl;
	m_window.draw(m_objectShape);
}
DestructWall::DestructWall(int x, int y, int size, sf::RenderWindow &w, std::vector<GameObject*> &pups)
: GameObject(x,y, size, w, pups){
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

 Worm::Worm(int x, int y, int size, sf::RenderWindow &w, std::vector<GameObject*> &pups)
    :GameObject(x, y, size, w, pups) {}
