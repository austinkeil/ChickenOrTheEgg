#include "Main.hpp"
#include "Game.h"

const int BOARD_WIDTH  = 2048;
const int BOARD_HEIGHT = 1024;

int main()
{
	Game g(BOARD_WIDTH, BOARD_HEIGHT);
    g.play();

	return 0;
}