#include "AI.hpp"
#include <limits>
#include <iostream>

AI::AI(char sign)
    : Player(sign)
{}

int AI::minimax(Board &board, int depth, bool isMax, int x, int y,char player)
{


    if(board.checkWinner(x,y,player))
    {
        if(player == 'O') return 10;
        else return -10;
    }

    if(board.isFull())
    {
        return 0;
    }

    if(isMax)
    {
        int best = -1000;
        for(int i = 0; i < board.getSize(); ++i)
        {
            for(int j = 0; j < board.getSize(); ++j)
            {
                if(board.getFields()[i][j] == ' ')
                {
                    board.putOnBoard(i,j,'O');
                    best = std::max(best,minimax(board,depth+1,!isMax,i,j,'O'));
                    board.eraseField(i,j);

                }
            }
        }
        return best;
    }
    else
    {
        int best = 1000;
        for(int i = 0; i < board.getSize(); ++i)
        {
            for(int j = 0; j < board.getSize(); ++j)
            {
                if(board.getFields()[i][j] == ' ')
                {
                    board.putOnBoard(i,j,'X');
                    best = std::min(best,minimax(board,depth+1,!isMax,i,j,'X'));
                    board.eraseField(i,j);

                }
            }
        }
        return best;

    }


}



std::pair<int, int> AI::findBestMove(Board &board)
{
    int bestValue = std::numeric_limits<int>::min();
    std::pair<int,int> bestMove = std::make_pair(-1,-1);
    for(int i = 0; i < board.getSize(); ++i)
    {
        for(int j = 0; j < board.getSize(); ++j)
        {

            if(board.getFields()[i][j] == ' ')
            {
                board.putOnBoard(i,j,getSign());
                int moveValue = minimax(board,0,false,i,j,'O');
                board.eraseField(i,j);

                if(moveValue > bestValue)
                {
                    bestMove = std::make_pair(i,j);
                    bestValue = moveValue;
                }
            }
        }
    }
    return bestMove;
}



std::pair<int, int> AI::move(Board &board)
{
    std::pair<int,int> coordinates = findBestMove(board);
    board.putOnBoard(coordinates.first,coordinates.second,getSign());
    return coordinates;
}
