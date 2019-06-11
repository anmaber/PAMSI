#pragma once
#include <vector>

using Fields = std::vector<std::vector<char>>;

class Board
{
    int size_;
    int winningNumber_;
    Fields fields_;

    bool validateCoordinates(int xCoordinate, int yCoordinate) const;

    bool checkWinnerVertically(int xCoordinate,int yCoordinate, char currentPlayer) const;
    bool checkWinnerHorizontally(int xCoordinate, int yCoordinate,char currentPlayer) const;
    bool checkWinnerDiagonally(int xCoordinate, int yCoordinate,char currentPlayer) const;
    bool checkWinnerAntiDiagonally(int xCoordinate, int yCoordinate,char currentPlayer) const;

public:

    Board() = delete;
    Board(int size, int winningNumber);
    Fields getFields() const;
    void printBoard() const;
    int getSize() const;
    int getWinningNumber() const;
    bool isFull() const;
    void eraseField(int xCoordinate, int yCoordinate);
    bool putOnBoard(int xCoordinate, int yCoordinate,char currentPlayer);
    bool checkWinner(int xCoordinate, int yCoordinate,char currentPlayer) const;


};
