#include <iostream>
#include "Game.hpp"

int main()
{
        std::cout<<"tic-tac-toe!\n";
        Game g(5);
        g.play();
	return 0;
}
