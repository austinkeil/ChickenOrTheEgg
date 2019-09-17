#include "GameObject.h"
#include "Position.h"
#include <string>
#include "rand.h"

GameObject::GameObject(std::string name, int x, int y)
{
    objectPos.m_x = x;
    objectPos.m_y = y;
    m_name = name;
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

std::string GameObject::m_getName()
{
    return m_name;
}

////////////////

 Worms::Worms(std::string name, int x, int y)
    :GameObject(name, x, y) {}



