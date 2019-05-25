#pragma once
#include <vector>

using BoardFields = std::vector<std::vector<char>>;

class Board
{
    int size_;
    BoardFields board_;

public:

    Board() = delete;
    Board(int size);
    BoardFields getBoard();
};
