#ifndef CHICKENORTHEEGG_GAMEOBJECTS_H
#define CHICKENORTHEEGG_GAMEOBJECTS_H
#include <string>
#include "Position.h"
#include <vector>

class GameObject
{
public:
    GameObject(int x, int y, int size, sf::RenderWindow &w, std::vector<GameObject*> &pups);
    Position objectPos;
    void drawMe();
    void iteratePowerUps();
    void setPos(int x, int y);
    sf::Vector2f getPos();
    void setColor(sf::Color color);
    void setTexture(std::string filename);

private:
    sf::RenderWindow &m_window;
    sf::RectangleShape m_objectShape;
    sf::Texture m_texture;
    std::vector<GameObject*> &m_powerUps;
};

class WallBlock : public GameObject
{
    const bool isDestruct = false;

public:
    WallBlock();
    WallBlock(int x, int y, int size, sf::RenderWindow &w, std::vector<GameObject*> &pups);
    // bool isDestruct() const;

};
class DestructWall : public GameObject
{
    // const bool isDestruct = true;
public:
DestructWall(int x, int y, int size, sf::RenderWindow &w, std::vector<GameObject*> &pups);
~DestructWall();

// bool isDestruct() const;
};

class Worm : public GameObject
{  // worms are the power ups
public:
    Worm(int x, int y, int size, sf::RenderWindow &w, std::vector<GameObject*> &pups);
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
