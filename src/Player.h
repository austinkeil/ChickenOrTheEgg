#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include "Actors.h"

class Player: public Actor{
public:
  Player();

  void setHitpoints(int hp);
  int getHitpoints();
private:
  int m_hitpoints;
};

#endif //PLAYER_INCLUDED