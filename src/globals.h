#ifndef CHICKENORTHEEGG_GLOBALS_H
#define CHICKENORTHEEGG_GLOBALS_H

#include <math.h>

const int PLAYERSIZE = 100;
const int BOMB_COUNT = 30;
const int BOARD_WIDTH  = 1500;
const int BOARD_HEIGHT = 1500;
const int BLOCK_COUNT = 15;
const int BLOCK_SIDE = BOARD_HEIGHT/BLOCK_COUNT;
const int NUMBER_OF_BLOCKS = pow((BLOCK_COUNT)/2, 2);
const int BOMB_TIME = 3;
const int EXPLODE_TIME = 4;

#endif //CHICKENORTHEEGG_GLOBALS_H