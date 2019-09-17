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

string GameObject::m_getName()
{
    return m_name;
}

////////////////

 Worms::Worms(string name, int x, int y)
    :GameObject(name, x, y) {}



