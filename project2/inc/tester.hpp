#pragma once
#include "merge.hpp"
#include "quick.hpp"
#include "heap.hpp"
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
    std::vector<Type> _data;
    std::ofstream _file;
    void generateRandom(int size, int percentageSorted);
    int duration();
    void writeToFile(int size, int percentage, int duration);

public:

    Tester();
    bool test();
};

template<typename Type>
void Tester<Type>::generateRandom(int size, int percentageSorted)
{
    if(!_data.empty()) _data.clear();
    std::srand(time(NULL));
    int numOfData = size*percentageSorted*0.01;
    std::generate_n(std::back_inserter(_data),numOfData,[n=0]()mutable {return n++;});
    std::generate_n(std::back_inserter(_data),size - numOfData,
                    [size](){return std::modulus<Type>()( std::rand(), size);});
}

/*
template<typename Type>
void Tester<Type>::generateWorstCase(int size)
{
    if(!_data.empty()) _data.clear();
    std::generate_n(std::back_inserter(_data),size/2,[n=0]()mutable {return n++;});
    std::generate_n(std::back_inserter(_data),size/2,
                    [size](){return std::modulus<Type>()( std::rand(), size);});
}
*/
template<typename Type>
int Tester<Type>::duration()
{
    auto start = std::chrono::high_resolution_clock::now();
    //quickSort(_data,0,_data.size()-1);
    //mergeSort(_data,0,_data.size()-1);
    heapSort(_data,_data.size());
    auto end = std::chrono::high_resolution_clock::now();

    if(! std::is_sorted(_data.begin(),_data.end())) throw std::runtime_error("chih");

    auto duration =std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    return duration.count();
}

template<typename Type>
void Tester<Type>::writeToFile(int size, int percentage, int duration)
{
    _file << size << ";" << percentage << ";" << duration << std::endl;
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
bool Tester<Type>::test()
{
    try{
         _file<< "size; percentage sorted; time \n";
        for(int s : _size)
        {
            for(int p : _percentage)
            {
                generateRandom(s,p);
                writeToFile(s,p, duration());
            }

        }

    }catch(std::runtime_error const& ex)
    {
        std::cerr<<"runtime error: "<<ex.what()<<std::endl;
        return false;
    }
    return true;
}
