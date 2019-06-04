#pragma once
#include "Board.hpp"
#include "Player.hpp"
#include <memory>

using PlayerPtr = std::shared_ptr<Player>;

class Game
{
    Board board_;

    PlayerPtr player1_ = std::make_shared<Player>('X');
    PlayerPtr player2_ = std::make_shared<Player>('O');

    PlayerPtr currentPlayer_;
    int currentXCoordinate_;
    int currentYCoordinate_;



public:
    Game(int size, int winningNumber);
    void getCoordinates();
    //bool markPlace();
    bool isCurrentPlayerWinner() const;
    void play();

};
