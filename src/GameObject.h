#ifndef CHICKENORTHEEGG_GAMEOBJECTS_H
#define CHICKENORTHEEGG_GAMEOBJECTS_H
#include <string>
#include "Position.h"

class GameObject
{
public:
    GameObject(std::string name, int x, int y);//use pos struct
    std::string m_getName();
    Position objectPos;

private:
    std::string m_name;

    

};

class WallBlock : public GameObject
{
    const bool isDestruct = false;

public:
    WallBlock();
    ~WallBlock();
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

class Worms : public GameObject
{  // worms are the power ups
public:
    Worms(std::string name, int x, int y);
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