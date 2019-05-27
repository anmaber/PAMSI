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
