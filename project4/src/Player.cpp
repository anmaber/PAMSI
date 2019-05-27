#include "Player.hpp"

Player::Player(char sign)
    : sign_(sign),
      turn_(0)
{}

bool Player::getTurn() const
{
    return turn_;
}

void Player::setTurn(bool value)
{
    turn_ = value;
}


char Player::getSign() const
{
    return sign_;
}
