#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include "Actors.h"

class Player: public Actors{
public:
  void setHitpoints(int hp);
  int getHitpoints();
private:
  int m_hitpoints;
};
