#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <string>
#include "Actors.h"

class Game
{
public:
    Game(int width, int height);
    void play();

private:
    int m_level;
    sf::RenderWindow m_window;
    Actor *player;
};

#endif // GAME_INCLUDED

