#pragma once
#include <string>

template<typename keyType>
int hash(keyType& key)
{
    return key % 100;
}

template <>
int hash(std::string& key)
{
    int hash = 0;
    for(const auto& letter: key)
    {
        hash+=letter;
    }
    return hash % 100;
}



