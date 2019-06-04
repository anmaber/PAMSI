#pragma once
#include "Board.hpp"
//#include "Player.hpp"


class Game
{
    Board board_;

    Player player1_ = Player::cross;
    Player player2_ = Player::circle;

    Player currentPlayer_;
    int currentXCoordinate_;
    int currentYCoordinate_;



public:
    Game(int size, int winningNumber);
    void getCoordinates();
    bool markPlace();
    bool isCurrentPlayerWinner();
    void play();

};
