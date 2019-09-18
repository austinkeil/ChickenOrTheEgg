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
    void drawGameBoardOne(sf::RenderWindow &w, std::vector<GameObject*> &pups);

    // ----- Getters -----
    std::vector<GameObject*> getBreakable();
    std::vector<GameObject*> getUnbreakable();

    int getLevel();
    Player* getPlayer();

    // ----- Setteres -----
    void setBreakable(std::vector<GameObject*> objects);
    void setUnbreakable(std::vector<GameObject*> objects);
    void setLevel(int lvl);
    void setPlayer(Player* player);


private:
    int m_level;
    sf::RenderWindow m_window;
    Player *m_player;
    std::vector<GameObject*> m_unbreakable;
    std::vector<GameObject*> m_breakable;

};

#endif // GAME_INCLUDED
