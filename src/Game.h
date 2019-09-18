#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <string>
#include <vector>
#include "Actor.h"
#include "GameObject.h"
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> master
#include "math.h"

const int PLAYERSIZE = 100;
const int BOARD_WIDTH  = 1500;
const int BOARD_HEIGHT = 1500;
const int BLOCK_COUNT = 15;
const int BLOCK_SIDE = BOARD_HEIGHT/BLOCK_COUNT;
const int NUMBER_OF_BLOCKS = pow((BLOCK_COUNT)/2, 2);
=======
#include "globals.h"
<<<<<<< HEAD
>>>>>>> 15e88880756a383890816c2310de0036549ce593
=======
>>>>>>> origin
=======
#include "globals.h"
>>>>>>> origin
>>>>>>> master

class Game
{
public:
    Game(int width, int height);
    void play();
    void generateBoard();
    void drawObjects();

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
    std::vector<GameObject*> &pups;
    int m_boardWidth;
    int m_blockWidth;

};

#endif // GAME_INCLUDED
