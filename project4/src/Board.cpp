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

Fields Board::getFields() const
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

int Board::getSize() const
{
    return size_;
}

bool Board::validateCoordinates(int xCoordinate, int yCoordinate)
{
    return fields_[xCoordinate][yCoordinate] == ' ';
}

bool Board::putOnBoard(int xCoordinate, int yCoordinate, Player currentPlayer)
{
    if(validateCoordinates(xCoordinate,yCoordinate))
    {
        fields_[xCoordinate][yCoordinate] = char(currentPlayer);
        return true;
    }
    return false;
}

bool Board::checkWinnerVertically(int xCoordinate,Player currentPlayer)
{
    for(int i = 0; i < size_; ++i)
        if (fields_[xCoordinate][i]!= char(currentPlayer)) return false;
    return true;
}

bool Board::checkWinnerHorizontally(int yCoordinate,Player currentPlayer)
{
    for(int i = 0; i < size_; ++i)
        if (fields_[i][yCoordinate]!=char(currentPlayer)) return false;
    return true;
}

bool Board::checkWinnerDiagonally(int xCoordinate, int yCoordinate, Player currentPlayer)
{
    if(xCoordinate!=yCoordinate) return false;
    for(int i = 0; i < size_ ; ++i)
        if(fields_[i][i] != char(currentPlayer)) return false;
    return true;
}

bool Board::checkWinnerAntiDiagonally(int xCoordinate, int yCoordinate, Player currentPlayer)
{
    if(xCoordinate != size_ - yCoordinate -1) return false;
    for(int i = 1; i < size_ ; ++i)
        if(fields_[i][size_ - i -1] != char(currentPlayer)) return false;
    return true;
}
