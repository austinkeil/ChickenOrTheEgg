#ifndef CHICKENORTHEEGG_GAMEOBJECTS_H
#define CHICKENORTHEEGG_GAMEOBJECTS_H
#include <string>
#include "Position.h"

class GameObject
{
public:
    GameObject(std::string name, int x, int y);//use pos struct
    std::string m_getName();
private:
    std::string m_name;
    bool isDestruct;
};

class WallBlock : public GameObject
{
    const bool isDestruct = false;
public:
    WallBlock();
    // bool isDestruct() const;

};
class DestructWall : public GameObject{
    const bool isDestruct = true;
public:
DestructWall();
// bool isDestruct() const;


};


#endif //CHICKENORTHEEGG_GAMEOBJECTS_H