#pragma once
#include "Board.hpp"
#include "Player.hpp"

class Game
{
    Board board_;
    Player player1_;
    Player player2_;

public:
    Game(int size);
};
