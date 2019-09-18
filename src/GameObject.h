#ifndef CHICKENORTHEEGG_GAMEOBJECTS_H
#define CHICKENORTHEEGG_GAMEOBJECTS_H
#include <string>
#include "Position.h"
#include <vector>

class GameObject
{
public:
    GameObject(std::string name, int x, int y, sf::RenderWindow &w, std::vector<GameObject*> &pups);
    Position objectPos;
    void drawMe();
    std::string getName();
    void iteratePowerUps();
    void setPos(int x, int y);
    void setColor(sf::Color color);

private:
    std::string m_name;
    sf::RenderWindow &m_window;
    sf::RectangleShape m_objectShape;
    std::vector<GameObject*> &m_powerUps;
};

class WallBlock : public GameObject
{
    const bool isDestruct = false;

public:
    WallBlock();
    WallBlock(std::string name, int x, int y, sf::RenderWindow &w, std::vector<GameObject*> &pups);
    // bool isDestruct() const;

};
class DestructWall : public GameObject
{
    // const bool isDestruct = true;
public:
DestructWall(std::string name, int x, int y, sf::RenderWindow &w, std::vector<GameObject*> &pups);
~DestructWall();

// bool isDestruct() const;
};

class Worm : public GameObject
{  // worms are the power ups
public:
    Worm(std::string name, int x, int y, sf::RenderWindow &w, std::vector<GameObject*> &pups);
private:
    // int point =100;

};


/*
class Grains : public GameObject
{
public:

private:
}
*/


#endif //CHICKENORTHEEGG_GAMEOBJECTS_H
