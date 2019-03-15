#pragma once
#include <string>
#include <stdexcept>
#include <iostream>

template<typename keyType>
int hash(const keyType& key)
{
    throw std::invalid_argument("you've chosen wrong type of key");
}

template <>
int hash(const int& key)
{
    return key % 100;
}

template <>
int hash(const std::string& key)
{
    int hash = 0;
    for(const auto& letter: key)
    {
        hash+=letter;
    }
    return hash % 100;
}

template<typename keyType, typename valType>
class Map{

    valType array[100];

public:
   void insert(const keyType& key, const valType& value);

};

template<typename keyType, typename valType>
void Map<keyType,valType>::insert(const keyType& key, const valType& value)
{
    try
    {
        array[hash<keyType>(key)] = value;

    }
    catch(std::invalid_argument const& ex)
    {
        std::cerr<<"invalid_argument: "<<ex.what()<<std::endl;
    }
}
