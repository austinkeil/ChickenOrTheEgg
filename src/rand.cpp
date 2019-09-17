#include "rand.h"

//Returns a number from 0 to max - 1
int randInt(int max)
{
  srand(time(NULL));

  return (rand() % max);
}
