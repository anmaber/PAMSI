#pragma once
#include <string>

int hash(std::string& key)
{
    int hash = 0;
    for(const auto& letter: key)
    {
        hash+=letter;
    }

    return hash % 100;
}

template<typename keyType, typename valType>
class Map
{

    valType array[100];

public:

};
