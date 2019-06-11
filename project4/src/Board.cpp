#include "Board.hpp"
#include <iostream>

Board::Board(int size,int winningNumber)
    : size_(size),
      winningNumber_(winningNumber)
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
    std::cout<<"TIC TAC TOE!\n";
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

bool Board::validateCoordinates(int xCoordinate, int yCoordinate) const
{
    return fields_[xCoordinate][yCoordinate] == ' ';
}

bool Board::putOnBoard(int xCoordinate, int yCoordinate, char currentPlayer)
{
    if(validateCoordinates(xCoordinate,yCoordinate))
    {
        fields_[xCoordinate][yCoordinate] = currentPlayer;
        return true;
    }
    return false;
}

bool Board::checkWinnerVertically(int xCoordinate, int yCoordinate, char currentPlayer) const
{
    int start =0, end = size_ -1;
    if(yCoordinate - winningNumber_ +1 >= 0 ) start = yCoordinate - winningNumber_ +1;
    if(yCoordinate + winningNumber_ - 1 <= end) end = yCoordinate + winningNumber_ - 1;
    int counter = 0;
    for(int i = start; i <= end; ++i)
    {
        if (fields_[xCoordinate][i]==currentPlayer) counter++;
        else counter = 0;
        if(counter == winningNumber_) return true;
    }
    return false;

}

bool Board::checkWinnerHorizontally(int xCoordinate, int yCoordinate,char currentPlayer) const
{
    int start =0, end = size_ -1;
    if(xCoordinate - winningNumber_ +1 >= 0 ) start = xCoordinate - winningNumber_ +1;
    if(xCoordinate + winningNumber_ - 1 <= end) end = xCoordinate + winningNumber_ - 1;

    int counter = 0;
    for(int i = start; i <= end; ++i)
    {
        if (fields_[i][yCoordinate]==currentPlayer) counter++;
        else counter = 0;
        if(counter == winningNumber_) return true;
    }
    return false;
}

bool Board::checkWinnerDiagonally(int xCoordinate, int yCoordinate,char currentPlayer) const
{
    int startX, endX, startY, endY;
    startX = xCoordinate - winningNumber_ +1;
    endX = xCoordinate + winningNumber_ - 1;
    startY = yCoordinate - winningNumber_ +1;
    endY = yCoordinate + winningNumber_ - 1;

    while(startX < 0 || startY < 0)
    {
        startX++;
        startY++;
    }

    while(endX >= size_ || endY >= size_)
    {
        endX--;
        endY--;
    }

    int  counter =0;

    for(int i = startX, j = startY; i <= endX && j<= endY; ++j, ++i)
    {
        if (fields_[i][j] == currentPlayer) counter++;
        else counter = 0;
        if(counter == winningNumber_) return true;
    }
    return false;

}

bool Board::checkWinnerAntiDiagonally(int xCoordinate, int yCoordinate,char currentPlayer) const
{
    int startX, endX, startY, endY;
    startX = xCoordinate + winningNumber_ -1;
    endX = xCoordinate - winningNumber_ + 1;
    startY = yCoordinate - winningNumber_ +1;
    endY = yCoordinate + winningNumber_ - 1;

    while (startX >= size_ || startY < 0)
    {
        startX--;
        startY++;
    }

    while (endX < 0 || endY >= size_)
    {
        endX++;
        endY--;
    }

    int counter = 0;

    for(int i = startX, j = startY; i >= endX && j<= endY; ++j, --i)
    {
        if (fields_[i][j] == currentPlayer) counter++;
        else counter = 0;
        if(counter == winningNumber_) return true;
    }
    return false;
}

bool Board::checkWinner(int xCoordinate, int yCoordinate, char currentPlayer) const
{
    return (
                checkWinnerVertically(xCoordinate,yCoordinate,currentPlayer)||
                checkWinnerHorizontally(xCoordinate,yCoordinate,currentPlayer) ||
                checkWinnerDiagonally(xCoordinate,yCoordinate,currentPlayer) ||
                checkWinnerAntiDiagonally(xCoordinate,yCoordinate,currentPlayer)
                );
}

void Board::eraseField(int xCoordinate, int yCoordinate)
{
    fields_[xCoordinate][yCoordinate] = ' ';
}

bool Board::isFull() const
{
    for(int i = 0 ;i < getSize();++i)
    {
        for(int j = 0; j< getSize(); ++j)
        {
            if(fields_[i][j]== ' ') return false;
        }
    }
    return true;
}

int Board::getWinningNumber() const
{
    return winningNumber_;
}
