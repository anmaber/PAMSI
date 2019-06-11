#include "Game.hpp"
#include <iostream>

Game::Game(int size, int winningNumber)
    : board_(size,winningNumber)
{
    currentPlayer_ = player1_;
}

bool Game::isCurrentPlayerWinner() const
{
    return board_.checkWinner(currentXCoordinate_, currentYCoordinate_, currentPlayer_->getSign());
}

void Game::play()
{
    int turn = 0 ;
    bool finished = false;

    board_.printBoard();

    while(!finished)
    {
        std::pair<int,int> coordinates = currentPlayer_->move(board_);

        currentXCoordinate_ = coordinates.first;
        currentYCoordinate_ = coordinates.second;

        std:: cout << "\033[2J\033[1;1H";

        board_.printBoard();
        if(isCurrentPlayerWinner())
        {
            std::cout <<currentPlayer_->getSign()<< " WON! \n";
            finished = true;
        }
        else if(++turn == board_.getSize() * board_.getSize())
        {
            std::cout<< "TIE! \n ";
            finished = true;
        }

        if(currentPlayer_ == player1_) currentPlayer_ = player2_;
        else currentPlayer_ = player1_;

    }

}
