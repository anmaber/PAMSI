#pragma once
#include "Player.hpp"

class AI : public Player
{
    std::pair<int,int> findBestMove(Board& board);
    int minimax(Board& board, int depth, bool isMax, int x, int y,char player);
public:
    AI() = default;
    AI(char sign);
    std::pair<int,int> move(Board& board);

};
