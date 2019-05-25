#include "Board.hpp"
#include <iostream>

Board::Board(int size)
    : size_(size)
{
    board_.resize(size);
    for(auto & b : board_)
    {
        b.resize(size,' ');
    }
}

BoardFields Board::getBoard()
{
    return board_;
}
