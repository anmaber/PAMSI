#pragma once
#include "merge.hpp"
#include "quick.hpp"
#include "heap.hpp"
#include "array.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <initializer_list>

template<typename Type>
class Tester
{
    std::vector<int> _size;
    std::vector<int> _percentage;
    std::ofstream _file;
    int duration(Type* array,int arraySize);
    void writeToFile(int size, int percentage, auto duration);

public:

    Tester();
    void test();
};


template<typename Type>
int Tester<Type>::duration(Type *array, int arraySize)
{
    auto start = std::chrono::high_resolution_clock::now();
    //quickSort(array,0,arraySize-1);
    //mergeSort(array,0,arraySize-1);
    heapSort(array,arraySize);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration =std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    return duration.count();
}

template<typename Type>
void Tester<Type>::writeToFile(int size, int percentage, auto duration)
{
    _file << percentage << ";" << size << ";" << duration << std::endl;
}

template<typename Type>
Tester<Type>::Tester()
{
    for(int i = 2; i <= 6 ; ++i)
    {
        _size.push_back(pow(10,i));
    }

    _percentage.push_back(0);
    _percentage.push_back(25);
    _percentage.push_back(50);
    _percentage.push_back(75);
    _percentage.push_back(95);
    _percentage.push_back(99);

    //_file.open("quick.csv", std::ios::out);
    //_file.open("merge.csv", std::ios::out);
    _file.open("heap.csv", std::ios::out);
}

template<typename Type>
void Tester<Type>::test()
{    
    _file<< "size; percentage sorted; time \n";
    for(int p : _percentage)
    {
        for(int s : _size)
        {
            Array<Type> a(s,p);
            writeToFile(s,p,duration(a._data,s));
        }
    }
}
