#include "Player.hpp"
#include <iostream>

Player::Player(char sign)
    : sign_(sign)
{}

char Player::getSign() const
{
    return sign_;
}

std::pair<int,int> Player::move(Board &board)
{
    std::pair<int,int> coordinates = std::make_pair(0,0);
    do
    {
       coordinates = setCoordinates(board.getSize());

    }while(!board.putOnBoard(coordinates.first,coordinates.second,getSign()));

    return coordinates;
}

std::pair<int, int> Player::setCoordinates(int max)
{
    int x=0,y=0;
    std::cout<<"Row: ";
    std::cin >> x;
    while(x < 0 || x >= max)
    {
        std::cout<<"invalid input, give row number again: ";
        std::cin >> x;
    }

    std::cout<<"Column: ";
    std::cin >> y;
    while(y < 0 || y >= max)
    {
        std::cout<<"invalid input, give column number again: ";
        std::cin >> y;
    }

    return std::make_pair(x,y);
}

bool Player::operator == (const Player &p)
{
    return getSign() == p.getSign();
}
