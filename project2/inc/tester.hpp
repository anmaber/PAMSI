#include "merge.hpp"
#include "quick.hpp"
#include "heap.hpp"
#include "random.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <iterator>
#include <cmath>


template<typename Type>
class Tester
{
    std::vector<int> _size;
    std::vector<Type> _data;
    std::ofstream _file;
    void generateRandom(int size);
    void generateInverted(int size);
    int duration();
    void writeToFile(int size, int duration);

public:

    Tester();
    bool test();
};

template<typename Type>
void Tester<Type>::generateRandom(int size)
{
    if(!_data.empty()) _data.clear();
    std::srand(time(NULL));
    std::generate_n(std::back_inserter(_data),size,
                    [size](){return std::modulus<Type>()( std::rand(), size);});
}

template<typename Type>
void Tester<Type>::generateInverted(int size)
{
    if(!_data.empty()) _data.clear();
    std::generate_n(std::back_inserter(_data),size,[size]() mutable {return size--;});
}

template<typename Type>
int Tester<Type>::duration()
{
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(_data,0,_data.size()-1);
    auto end = std::chrono::high_resolution_clock::now();

    if(! std::is_sorted(_data.begin(),_data.end())) throw std::runtime_error("chih");

    auto duration =std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    return duration.count();
}

template<typename Type>
void Tester<Type>::writeToFile(int size, int duration)
{
    _file << size << ";" << duration << std::endl;
}

template<typename Type>
Tester<Type>::Tester()
{
    for(int i = 2; i <= 6 ; ++i)
    {
        _size.push_back(pow(10,i));
    }

    _file.open("quick.csv", std::ios::out);
}

template<typename Type>
bool Tester<Type>::test()
{
    try{
         _file<< "for random array \n";
        for(auto s : _size)
        {
            generateRandom(s);
            writeToFile(s, duration());
        }
         _file<< "for inverted array \n";
        for(auto s : _size)
        {
            generateInverted(s);
            writeToFile(s, duration());
        }


    }catch(std::runtime_error const& ex)
    {
        std::cerr<<"runtime error: "<<ex.what()<<std::endl;
        return false;
    }
    return true;
}
