#include <iostream>
#include "Game.hpp"

int main()
{
        std::cout<<"tic-tac-toe!\n";
        Game g(3,3);
        g.play();
	return 0;
}
