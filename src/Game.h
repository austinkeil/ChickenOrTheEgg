#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <string>

class Game
{
public:
    Game(int width, int height);
    void play();

private:
    int m_level;
    sf::RenderWindow m_window;
};

#endif // GAME_INCLUDED

