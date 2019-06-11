#include <iostream>
#include "Game.hpp"

int main()
{
        std::cout<<"TIC TAC TOE!\n";

        int size =0;
        int winning = 0;
        bool playing = true;

        while(playing)
        {
            std::cout<<"Board size: ";
            std::cin>>size;
            std::cout<<"Number of winning in line: ";
            std::cin>>winning;
            std:: cout << "\033[2J\033[1;1H";

            Game g(size,winning);
            g.play();

            std::cout << "Do you wanna play again? (0 - no, 1 - yes) ";
            std::cin>> playing;

        }

	return 0;
}
