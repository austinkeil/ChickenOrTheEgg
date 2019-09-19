#ifndef CHICKENORTHEEGG_GAMEOBJECTS_H
#define CHICKENORTHEEGG_GAMEOBJECTS_H
#include <string>
#include <vector>

class GameObject
{
public:
    GameObject(int x, int y, int size, sf::RenderWindow &w, std::vector<GameObject*> &pups);
    void drawMe();
    void iteratePowerUps();
    void setPos(int x, int y);
    void setPos(sf::Vector2f v);
    sf::Vector2f getPos();
    void setColor(sf::Color color);
    void setTexture(std::string filename);
    sf::RectangleShape getShape();
    void display();
protected:
    sf::RectangleShape m_objectShape;
    sf::RenderWindow &m_window;
    std::vector<GameObject*> &m_pups;
    std::vector<GameObject*> m_worms;

private:
    sf::Texture m_texture;

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
