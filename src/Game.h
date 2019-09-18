#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <string>
#include <vector>
#include "Actor.h"
#include "GameObject.h"
#include "math.h"
#include "globals.h"

class Game
{
public:
    Game(int width, int height);
    void play();
    void generateBreakables();
    void generateUnbreakables();
    void drawUnbreakables();
    void drawBreakables();
    void generateMonsters();
    void drawMonsters();

    // ----- Getters -----
    std::vector<GameObject*> &getBreakable();
    std::vector<GameObject*> &getUnbreakable();

    int getLevel();
    Player* getPlayer();

    // ----- Setteres -----
    void setBreakable(std::vector<GameObject*> objects);
    void setUnbreakable(std::vector<GameObject*> objects);
    void setLevel(int lvl);
    void setPlayer(Player* player);


protected:
    int m_level;
    sf::RenderWindow m_window;
    Player *m_player;
    std::vector<GameObject*> m_unbreakable;
    std::vector<GameObject*> m_breakable;
    std::vector<GameObject*> m_pups;
    std::vector<Monster*> m_enemies;
    int m_boardWidth;
    int m_blockWidth;
};

#endif // GAME_INCLUDED
