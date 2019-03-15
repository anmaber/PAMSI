#include "map.hpp"
#include <iostream>

int main()
{
    try{
    Map<std::string,int> map;
    map.insert("three",3);

    std::cout<<map["three"];
    map["three"] = 6;
    map.remove("three");
    std::cout<<map["three"];

    }
    catch(std::invalid_argument const& ex)
    {
        std::cerr<<"invalid argument: "<<ex.what()<<std::endl;
    }
    return 0;
}
