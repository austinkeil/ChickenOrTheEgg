#include "GameObject.h"
#include "Position.h"
#include <string>
#include "rand.h"

GameObject::GameObject(int x, int y, int size, sf::RenderWindow &w, std::vector<GameObject*> &pups)
: m_window(w), m_objectShape(sf::Vector2f(size,size)), m_powerUps(pups)
{
    objectPos.m_x = x;
    objectPos.m_y = y;
}

void GameObject::setColor(sf::Color color) {
	m_objectShape.setFillColor(color);
}
void GameObject::setTexture(std::string filename) {
	if (!m_texture.loadFromFile(filename)) {
		std::cout << "Failed to load texture from " << filename << std::endl;
	}
	m_objectShape.setTexture(&m_texture);
}

WallBlock::WallBlock(int x, int y, int size, sf::RenderWindow &w, std::vector<GameObject*> &pups)
: GameObject(x,y, size, w,pups) {

}

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
