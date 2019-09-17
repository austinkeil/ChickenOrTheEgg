#include "GameObject.h"
#include "Position.h"
#include <string>
#include "rand.h"

<<<<<<< HEAD
GameObject::GameObject(){}
GameObject::GameObject(std::string name, int x, int y, sf::RenderWindow &w)
: m_window(w)
=======
GameObject::GameObject(std::string name, int x, int y, sf::RenderWindow &w, std::vector<GameObject*> &pups)
: m_window(w), m_powerUps(pups)
>>>>>>> 55c2895eeb5c466fa6d2f3c84c3a7c76360c75dc
{
    objectPos.m_x = x;
    objectPos.m_y = y;
	  m_name = name;
}

WallBlock::WallBlock(std::string name, int x, int y, sf::RenderWindow &w, std::vector<GameObject*> &pups)
: GameObject(name,x,y,w,pups) {}

void GameObject::drawMe() {
	m_window.draw(m_playerShape);
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
