#include "Main.hpp"
#include "Game.h"
#include <ctime>

int main()
{
	srand(time(0));
	Game g(BOARD_HEIGHT, BOARD_WIDTH);
    g.play();

	return 0;
}