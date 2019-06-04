#pragma once
#include "Board.hpp"

class Player
{
    char sign_;
    std::pair<int,int> getCoordinates(int max);

public:
    Player(char sign);
    Player() = default;
    virtual std::pair<int,int> move(Board& board);
    bool operator == (const Player& p);
    char getSign() const;

    virtual ~Player(){}
};
