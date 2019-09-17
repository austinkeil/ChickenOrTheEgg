#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <string>
#include "Actor.h"

class Game
{
public:
    Game(int width, int height);
    void play();

private:
    int m_level;
    sf::RenderWindow m_window;
    Player *m_player;
};

#endif // GAME_INCLUDED

