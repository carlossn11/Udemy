#include "../include/player.h"

Player::Player() : health(100), x(0), y(0) {}
Player::~Player() {}
void Player::getHealth() {std::cout << "Health: " << health << "\n";}