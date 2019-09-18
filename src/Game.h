#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <string>
#include <vector>
#include "Actor.h"
#include "GameObject.h"
#include "math.h"

const int BOARD_WIDTH  = 1500;
const int BOARD_HEIGHT = 1500;
const int BLOCK_COUNT = 15;
const int BLOCK_SIDE = BOARD_HEIGHT/BLOCK_COUNT;
const int NUMBER_OF_BLOCKS = pow((BLOCK_COUNT)/2, 2);

class Game
{
public:
    Game(int width, int height);
    void play();
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    void drawGameBoardOne(sf::RenderWindow &w,std::vector<GameObject*> getBreakable());
=======
    void drawGameBoardOne(sf::RenderWindow &w, std::vector<GameObject*> &pups);
>>>>>>> 55c2895eeb5c466fa6d2f3c84c3a7c76360c75dc
=======
    void drawGameBoardOne(sf::RenderWindow &w, std::vector<GameObject*> &pups);
>>>>>>> 6a07d42fcf0fd63a491985311d1b99412c9383ef
=======
    void generateBoard();
    void drawObjects();
>>>>>>> d1c6938b6653a87a649367193449da31055b6e11

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


private:
    int m_level;
    sf::RenderWindow m_window;
    Player *m_player;
    std::vector<GameObject*> m_unbreakable;
    std::vector<GameObject*> m_breakable;
    int m_boardWidth;
    int m_blockWidth;

};

#endif // GAME_INCLUDED
