#include "Monster.h"
#include "Actor.h"

Monster :: Monster(float x, float y, float size, sf::RenderWindow &w, std::vector<GameObject*> &breakable, std::vector<GameObject*> &unbreakable)
: Actor(x, y, size, w, breakable, unbreakable)
{}

