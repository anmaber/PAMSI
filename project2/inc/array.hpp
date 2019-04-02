#pragma once
#include <cstdlib>

template<typename Type>
struct Array
{
    Type* _data;
    Array(int size, int percentageSorted);
    ~Array();
};

template<typename Type>
Array<Type>::Array(int size, int percentageSorted)
{
    _data = new Type[size];

    for(int i = 0; i< size*percentageSorted*0.01 ;++i)
    {
        _data[i]=i;
    }
    for(int i = size*percentageSorted*0.01;i<size ;++i)
    {
        _data[i] = rand()%size;
    }

}

template<typename Type>
Array<Type>::~Array()
{
    delete[] _data;
}
