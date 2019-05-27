#pragma once
#include <vector>

using Fields = std::vector<std::vector<char>>;

class Board
{
    int size_;
    Fields fields_;

public:

    Board() = delete;
    Board(int size);
    Fields getFields();
    void printBoard() const;
};
