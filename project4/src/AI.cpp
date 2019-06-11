#include "AI.hpp"
#include <limits>
#include <iostream>

AI::AI(char sign)
    : Player(sign)
{}

int AI::minimax(Board &board, int depth, bool isMax, int x, int y,char player,int alpha, int beta)
{


    if(depth == 5 || board.isFull() || board.checkWinner(x,y,player))
    {
        if(player == 'O') return evaluateBoard(board,x,y,'X');
        else return -evaluateBoard(board,x,y,'O');
    }

    int best = 0;
    depth++;

    if(isMax)
    {
        best = alpha;
        for(int i = 0; i < board.getSize(); ++i)
        {
            for(int j = 0; j < board.getSize(); ++j)
            {
                if(board.getFields()[i][j] == ' ')
                {
                    board.putOnBoard(i,j,'O');
                    best = std::max(best,minimax(board,depth,!isMax,i,j,'O',alpha,beta));
                    alpha =std::max(best,alpha);
                    board.eraseField(i,j);
                }
                if(alpha >= beta) break;

            }
        }
    }
    else
    {
        best = beta;
        for(int i = 0; i < board.getSize(); ++i)
        {
            for(int j = 0; j < board.getSize(); ++j)
            {
                if(board.getFields()[i][j] == ' ')
                {
                    board.putOnBoard(i,j,'X');
                    best = std::min(best,minimax(board,depth,!isMax,i,j,'X',alpha,beta));
                    beta = std::min(best,beta);
                    board.eraseField(i,j);
                }
                if(alpha >= beta) break;
            }
        }
    }
    return best;
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
                int moveValue = minimax(board,0,false,i,j,'O',bestValue,std::numeric_limits<int>::max());
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

    int eval = 0;
    if ((xCoordinate == (board.getSize() - 1) / 2) && (yCoordinate == (board.getSize() - 1) / 2))
        eval += 1;
    eval += 5 * evaluateVertically(board,xCoordinate,yCoordinate,player);
    eval += 5 * evaluateHorizontally(board,xCoordinate,yCoordinate,player);
    eval += 5 * evaluateDiagonally(board,xCoordinate,yCoordinate,player);
    eval += 5 * evaluateAntidiagonally(board,xCoordinate,yCoordinate,player);

    return eval;
}

int AI::evaluateVertically(const Board &board, int xCoordinate, int yCoordinate, char currentPlayer) const
{
    int start =0, end = board.getSize()-1;
    if(yCoordinate - board.getWinningNumber() +1 >= 0 ) start = yCoordinate - board.getWinningNumber() +1;
    if(yCoordinate + board.getWinningNumber() - 1 <= end) end = yCoordinate + board.getWinningNumber() - 1;
    int counterTop = 0, counterBottom = 0;
    int opponentCounterTop = 0, opponentCounterBottom = 0;
    for(int i = start; i < yCoordinate; ++i)
    {
        if (board.getFields()[xCoordinate][i]==currentPlayer)
        {
            counterBottom++;
            opponentCounterBottom = 0;
        }
        else if (board.getFields()[xCoordinate][i]== ' ');
        else
        {
            opponentCounterBottom++;
            counterBottom = 0;
        }
    }

    for(int i = end; i > yCoordinate; --i)
    {
        if (board.getFields()[xCoordinate][i]==currentPlayer)
        {
            counterTop++;
            opponentCounterTop = 0;
        }
        else if (board.getFields()[xCoordinate][i]== ' ');
        else
        {
            opponentCounterTop++;
            counterTop = 0;
        }
    }
    if(opponentCounterBottom+opponentCounterTop == board.getWinningNumber() - 1) return 1000;
    if(counterBottom+counterTop== board.getWinningNumber() - 1) return 100;
    return counterBottom+counterTop;
}

int AI::evaluateHorizontally(const Board &board, int xCoordinate, int yCoordinate, char currentPlayer) const
{
    int start =0, end = board.getSize() -1;
    if(xCoordinate - board.getWinningNumber() +1 >= 0 ) start = xCoordinate -  board.getWinningNumber() +1;
    if(xCoordinate +  board.getWinningNumber() - 1 <= end) end = xCoordinate + board.getWinningNumber() - 1;

    int counterLeft = 0, counterRight = 0;
    int opponentCounterLeft = 0, opponentCounterRight = 0;

    for(int i = start; i < xCoordinate; ++i)
    {
        if (board.getFields()[i][yCoordinate]==currentPlayer)
        {
            counterLeft++;
            opponentCounterLeft = 0;
        }
        else if (board.getFields()[i][yCoordinate]== ' ');
        else
        {
            opponentCounterLeft++;
            counterLeft = 0;
        }
    }

    for(int i = end; i > xCoordinate; --i)
    {
        if (board.getFields()[i][yCoordinate]==currentPlayer)
        {
            counterRight++;
            opponentCounterRight = 0;
        }
        else if (board.getFields()[i][yCoordinate]== ' ');
        else
        {
            opponentCounterRight++;
            counterRight = 0;
        }
    }
    if(opponentCounterLeft+opponentCounterRight == board.getWinningNumber() - 1) return 1000;
    if(counterLeft+counterRight == board.getWinningNumber() - 1) return 100;
    return counterLeft+counterRight;

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

    int  counter1 =0, counter2 = 0;
    int opponentCounter1 = 0, opponentCounter2=0;

    for(int i = startX, j = startY; i < xCoordinate && j< yCoordinate; ++j, ++i)
    {
        if (board.getFields()[i][j]==currentPlayer)
        {
            counter1++;
            opponentCounter1 = 0;
        }
        else if (board.getFields()[i][j]== ' ');
        else
        {
            opponentCounter1++;
            counter1 = 0;
        }
    }
    for(int i = endX, j = endY; i > xCoordinate && j > yCoordinate; --j, --i)
    {
        if (board.getFields()[i][j]==currentPlayer)
        {
            counter2++;
            opponentCounter2 = 0;
        }
        else if (board.getFields()[i][j]== ' ');
        else
        {
            opponentCounter2++;
            counter2 = 0;
        }
    }
    if(opponentCounter1+opponentCounter2 == board.getWinningNumber() - 1) return 1000;
    if(counter1+counter2 == board.getWinningNumber() - 1) return 100;
    return counter1+counter2;

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

    int  counter1 =0, counter2 = 0;
    int opponentCounter1 = 0, opponentCounter2=0;

    for(int i = startX, j = startY; i > xCoordinate && j< yCoordinate; ++j, --i)
    {
        if (board.getFields()[i][j]==currentPlayer)
        {
            counter1++;
            opponentCounter1 = 0;
        }
        else if (board.getFields()[i][j]== ' ');
        else
        {
            opponentCounter1++;
            counter1 = 0;
        }

    }

    for(int i = endX, j = endY; i < xCoordinate && j > yCoordinate; --j, ++i)
    {
        if (board.getFields()[i][j]==currentPlayer)
        {
            counter2++;
            opponentCounter2 = 0;
        }
        else if (board.getFields()[i][j]== ' ');
        else
        {
            opponentCounter2++;
            counter2 = 0;
        }

    }

    if(opponentCounter1+opponentCounter2 == board.getWinningNumber() - 1) return 1000;
    if(counter1+counter2 == board.getWinningNumber() - 1) return 100;
    return counter1+counter2;
}
