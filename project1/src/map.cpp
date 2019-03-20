#include "map.hpp"
#include <iostream>
#include <map>


int main()
{
    try{
    Map<std::string,int> map;
    map.insert("apple",3);

    std::cout<<map["apple"];
    map["apple"] = 6;
    std::cout<<map["apple"];

    map.remove("apple");
    std::cout<<map["apple"];

    }
    catch(std::invalid_argument const& ex)
    {
        std::cerr<<"invalid argument: "<<ex.what()<<std::endl;
    }

    std::map<std::string, int> map;
    map["apple"] = 3;
    std::cout<<std::endl<<map["apple"]<<std::endl;
    map.insert(std::pair<std::string,int>("peach",9));
    std::cout<<map["peach"]<<std::endl;
    map.erase("peach");
    map["orange"]=2;

    for (auto it=map.begin(); it!=map.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';



    return 0;
}
