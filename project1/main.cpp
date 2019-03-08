#include "list.hpp"

int main()
{
    List<int> list;
    list.push_front(4);
    list.push_back(1);
    list.push_back(3);
    list.push_front(5);
    return 0;
}
