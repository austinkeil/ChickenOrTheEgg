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
private:
    std::string m_name;
    sf::RectangleShape m_playerShape;
    sf::RenderWindow &m_window;
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
    const bool isDestruct = true;
public:
DestructWall();
~DestructWall();

// bool isDestruct() const;
};

class Worm : public GameObject
{  // worms are the power ups
public:
    Worm(std::string name, int x, int y, sf::RenderWindow &w, std::vector<GameObject*> &pups);
private:
};


/*
class Grains : public GameObject
{
public:

private:
}
*/


#endif //CHICKENORTHEEGG_GAMEOBJECTS_H
