#include "map.hpp"
#include <iostream>

int main()
{
    Map<std::string,int> map;
    map.insert("hello",1);

    return 0;
}
