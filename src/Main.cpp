#include "Main.hpp"
#include "Game.h"

const int BOARD_WIDTH  = 1500;
const int BOARD_HEIGHT = 1500;

int main()
{
	Game g(BOARD_HEIGHT, BOARD_WIDTH);
    g.play();

	return 0;
}