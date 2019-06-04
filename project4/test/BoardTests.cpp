#include <gtest/gtest.h>
#include "Board.hpp"

struct BoardTests : public::testing::Test
{
    int size = 3;
    Board board{size,3};
};

TEST_F(BoardTests, checkIfAllFieldsInNewBoardAreSpaces)
{
    bool areSpaces = true;
    Fields f = board.getFields();

    for(int i=0; i < size ; ++i)
    {
        for(int j=0; j < size ; ++j)
        {
            if(f.at(i).at(j) != ' ') areSpaces = false;
        }
    }

    ASSERT_TRUE(areSpaces);
}
