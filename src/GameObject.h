#ifndef CHICKENORTHEEGG_GAMEOBJECTS_H
#define CHICKENORTHEEGG_GAMEOBJECTS_H
#include <string>
#include "Position.h"

class GameObject
{
public:
    GameObject(std::string name, int x, int y, sf::RenderWindow &w);
    Position objectPos;
    void drawMe();
    std::string getName();
private:
    std::string m_name;
    sf::RectangleShape m_playerShape;
    sf::RenderWindow &m_window;
};

class WallBlock : public GameObject
{
    const bool isDestruct = false;


public:
    WallBlock();
    // bool isDestruct() const;

};
class DestructWall : public GameObject
{
    const bool isDestruct = true;
public:
DestructWall(std::string name, int x, int y, sf::RenderWindow &w);
~DestructWall();

// bool isDestruct() const;
};

class Worm : public GameObject
{  // worms are the power ups
public:
    Worm();
    Worm(std::string name, int x, int y, sf::RenderWindow &w);
private:
    int point =100;

};


/*
class Grains : public GameObject
{
public:

private:
}
*/


#endif //CHICKENORTHEEGG_GAMEOBJECTS_H