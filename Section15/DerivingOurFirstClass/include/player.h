#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>

class Player {
 public:
  int x, y;
  int health;
  void getHealth();
  Player();
  ~Player();
};

#endif // PLAYER_H_