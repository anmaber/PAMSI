#pragma once
#include <vector>

using Fields = std::vector<std::vector<char>>;
/*
enum class Player: char
{
    cross = 'X',
    circle = 'O'
};*/

class Board
{
    int size_;
    int winningNumber_;
    Fields fields_;

    bool validateCoordinates(int xCoordinate, int yCoordinate);

    bool checkWinnerVertically(int xCoordinate,int yCoordinate, char currentPlayer);
    bool checkWinnerHorizontally(int xCoordinate, int yCoordinate,char currentPlayer);
    bool checkWinnerDiagonally(int xCoordinate, int yCoordinate,char currentPlayer);
    bool checkWinnerAntiDiagonally(int xCoordinate, int yCoordinate,char currentPlayer);

public:

    Board() = delete;
    Board(int size, int winningNumber);
    Fields getFields() const;
    void printBoard() const;
    int getSize() const;

    bool putOnBoard(int xCoordinate, int yCoordinate,char currentPlayer);
    bool checkWinner(int xCoordinate, int yCoordinate,char currentPlayer);

};
