#include "Main.hpp"
#include "Game.h"

const int BOARD_WIDTH  = 2000;
const int BOARD_HEIGHT = 1000;

int main()
{
	Game g(BOARD_HEIGHT, BOARD_WIDTH);
    g.play();

	return 0;
}