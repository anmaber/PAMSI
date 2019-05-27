#include <iostream>
#include "Game.hpp"

int main()
{
        std::cout<<"tic-tac-toe!\n";
        Game g(3);
        Board b(6);
        b.printBoard();
	return 0;
}
