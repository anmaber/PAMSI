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

int AI::evaluateBoard(const Board &board, int xCoordinate, int yCoordinate, char player) const
{

    return  evaluateVertically(board,xCoordinate,yCoordinate,player)
            + evaluateHorizontally(board,xCoordinate,yCoordinate,player)
            + evaluateDiagonally(board,xCoordinate,yCoordinate,player)
            + evaluateAntidiagonally(board,xCoordinate,yCoordinate,player);

}

int AI::evaluateVertically(const Board &board, int xCoordinate, int yCoordinate, char currentPlayer) const
{
    int start =0, end = board.getSize()-1;
    if(yCoordinate - board.getWinningNumber() +1 >= 0 ) start = yCoordinate - board.getWinningNumber() +1;
    if(yCoordinate + board.getWinningNumber() - 1 <= end) end = yCoordinate + board.getWinningNumber() - 1;
    int counter = 0;
    for(int i = start; i <= end; ++i)
    {
        if (board.getFields()[xCoordinate][i]==currentPlayer) counter+=2;
        else if (board.getFields()[xCoordinate][i]== ' ') counter++;
        else counter = 0;

    }
    return counter;
}

int AI::evaluateHorizontally(const Board &board, int xCoordinate, int yCoordinate, char currentPlayer) const
{
    int start =0, end = board.getSize() -1;
    if(xCoordinate - board.getWinningNumber() +1 >= 0 ) start = xCoordinate -  board.getWinningNumber() +1;
    if(xCoordinate +  board.getWinningNumber() - 1 <= end) end = xCoordinate + board.getWinningNumber() - 1;

    int counter = 0;
    for(int i = start; i <= end; ++i)
    {
        if (board.getFields()[i][yCoordinate]==currentPlayer) counter+=2;
        else if (board.getFields()[i][yCoordinate]== ' ') counter++;
        else counter = 0;

    }
    return counter;
}

int AI::evaluateDiagonally(const Board &board, int xCoordinate, int yCoordinate, char currentPlayer) const
{
    int startX, endX, startY, endY;
    startX = xCoordinate - board.getWinningNumber() +1;
    endX = xCoordinate + board.getWinningNumber() - 1;
    startY = yCoordinate - board.getWinningNumber() +1;
    endY = yCoordinate + board.getWinningNumber() - 1;

    while(startX < 0 || startY < 0)
    {
        startX++;
        startY++;
    }

    while(endX >= board.getSize() || endY >= board.getSize())
    {
        endX--;
        endY--;
    }

    int  counter =0;

    for(int i = startX, j = startY; i <= endX && j<= endY; ++j, ++i)
    {
        if (board.getFields()[i][j] == currentPlayer) counter+=2;
        else if(board.getFields()[i][j] == ' ') counter++;
        else counter = 0;
    }
    return counter;

}

int AI::evaluateAntidiagonally(const Board &board, int xCoordinate, int yCoordinate, char currentPlayer) const
{
    int startX, endX, startY, endY;
    startX = xCoordinate + board.getWinningNumber() -1;
    endX = xCoordinate - board.getWinningNumber() + 1;
    startY = yCoordinate - board.getWinningNumber() +1;
    endY = yCoordinate + board.getWinningNumber() - 1;

    while (startX >= board.getSize() || startY < 0)
    {
        startX--;
        startY++;
    }

    while (endX < 0 || endY >= board.getSize())
    {
        endX++;
        endY--;
    }

    int counter = 0;

    for(int i = startX, j = startY; i >= endX && j<= endY; ++j, --i)
    {
        if (board.getFields()[i][j] == currentPlayer) counter+=2;
        else if(board.getFields()[i][j] == ' ') counter++;
        else counter = 0;

    }
    return counter;

}
