#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <string>
#include <vector>
#include "Actor.h"
#include "GameObject.h"

class Game
{
public:
    Game(int width, int height);
    void play();
    void drawGameBoardOne();

    // ----- Getters -----
    std::vector<GameObject*> getObjects();
    int getLevel();
    Player* getPlayer();

    // ----- Setteres -----
    void setObjects(std::vector<GameObject*> objects);
    void setLevel(int lvl);
    void setPlayer(Player* player);


private:
    int m_level;
    sf::RenderWindow m_window;
    Player *m_player;
    std::vector<GameObject*> m_objects;

};

#endif // GAME_INCLUDED
