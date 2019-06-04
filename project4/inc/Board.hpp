#pragma once
#include <vector>

using Fields = std::vector<std::vector<char>>;

enum class Player: char
{
    cross = 'X',
    circle = 'O'
};

class Board
{
    int size_;
    int winningNumber_;
    Fields fields_;

public:

    Board() = delete;
    Board(int size, int winningNumber);
    Fields getFields() const;
    void printBoard() const;
    int getSize() const;
    bool validateCoordinates(int xCoordinate, int yCoordinate);
    bool putOnBoard(int xCoordinate, int yCoordinate, Player currentPlayer);
    bool checkWinnerVertically(int xCoordinate,int yCoordinate, Player currentPlayer);
    bool checkWinnerHorizontally(int xCoordinate, int yCoordinate,Player currentPlayer);
    bool checkWinnerDiagonally(int xCoordinate, int yCoordinate, Player currentPlayer);
    bool checkWinnerAntiDiagonally(int xCoordinate, int yCoordinate, Player currentPlayer);

};
