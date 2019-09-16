#ifndef CHICKENORTHEEGG_GAMEOBJECTS_H
#define CHICKENORTHEEGG_GAMEOBJECTS_H

struct Position
{
	int m_x;
	int m_y;
};

class GameObject
{
public:
    GameObject(std::string name, int x, int y);
    std::string m_getName();
private:
    std::string m_name;
};

class WallBlock : public GameObject
{
public:
private:
};

#endif //CHICKENORTHEEGG_GAMEOBJECTS_H