#include "Game.hpp"
#include <iostream>

Game::Game(int size, int winningNumber)
    : board_(size,winningNumber)
{
    currentPlayer_ = player1_;
}

//dopisac ut
/*
void Game::getCoordinates()
{
    std::cout<<"coordinate X: ";
    std::cin >> currentXCoordinate_;
    while(currentXCoordinate_ < 0 || currentXCoordinate_ >= board_.getSize())
    {
        std::cout<<"invalid input\n";
        std::cin >> currentXCoordinate_;
    }

    std::cout<<"coordinate Y: ";
    std::cin >> currentYCoordinate_;
    while(currentYCoordinate_ < 0 || currentYCoordinate_ >= board_.getSize())
    {
        std::cout<<"invalid input\n";
        std::cin >> currentYCoordinate_;
    }
}*/
/*
bool Game::markPlace()
{
    return board_.putOnBoard(currentXCoordinate_,currentYCoordinate_, currentPlayer_);
}
*/
bool Game::isCurrentPlayerWinner()
{
    return (
                board_.checkWinnerVertically(currentXCoordinate_, currentYCoordinate_, currentPlayer_->getSign())||
                board_.checkWinnerHorizontally(currentXCoordinate_,currentYCoordinate_,currentPlayer_->getSign()) ||
                board_.checkWinnerDiagonally(currentXCoordinate_,currentYCoordinate_,currentPlayer_->getSign()) ||
                board_.checkWinnerAntiDiagonally(currentXCoordinate_,currentYCoordinate_,currentPlayer_->getSign())
                );
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

        board_.printBoard();
        if(isCurrentPlayerWinner())
        {
            std::cout<< "Wygrał ziomus: " <<currentPlayer_->getSign()<< "\n";
            finished = true;
        }
        else if(++turn == board_.getSize() * board_.getSize())
        {
            std::cout<< "Remis \n ";
            finished = true;
        }

        if(currentPlayer_ == player1_)
            currentPlayer_ = player2_;
        else
            currentPlayer_ = player1_;

    }

}
