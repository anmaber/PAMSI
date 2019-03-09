#include "list.hpp"

int main()
{
    List<int> list;
    list.push_back(4);
    list.display();
    list.push_front(1);
    list.display();
    list.push_back(3);
    //list.insert(9,4);
    list.display();
    //list[3]=9;
    list.display();
    //fix segmentation fault when use [] more then once

    std::cout<<list[2];

    return 0;
}
