#include "Board.hpp"
#include <iostream>

Board::Board(int size)
    : size_(size)
{
    fields_.resize(size);
    for(auto & b : fields_)
    {
        b.resize(size,' ');
    }
}

Fields Board::getFields()
{
    return fields_;
}

void Board::printBoard() const
{
    std::cout<<" |";
    for(int i = 0; i < size_; ++i)
        std::cout<< i <<"|";
    std::cout<<"\n";
    for(int i = 0; i < size_; ++i)
    {
        std::cout<<i<<"|";
        for(int j =0; j < size_; ++j)
                std::cout<<fields_[i][j]<<"|";
        std::cout<<"\n";
    }
}
