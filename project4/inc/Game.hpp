#pragma once

#include <memory>

#include "Board.hpp"
#include "AI.hpp"

using PlayerPtr = std::shared_ptr<Player>;

class Game
{
    Board board_;

    PlayerPtr player1_ = std::make_shared<Player>('X');
    PlayerPtr player2_ = std::make_shared<AI>('O');

    PlayerPtr currentPlayer_;

    int currentXCoordinate_;
    int currentYCoordinate_;

    bool isCurrentPlayerWinner() const;

public:

    Game(int size, int winningNumber);
    void play();

};
