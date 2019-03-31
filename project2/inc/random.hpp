#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iterator>
#include <iostream>


template <typename Type>
std::vector<Type> generateRandomArray(int size)
{
    std::srand(time(NULL));
    std::vector<Type> v;
    std::generate_n(std::back_inserter(v),size,[size](){return std::modulus<Type>()( std::rand(), size);});

    return v;
}

template <typename Type>
std::vector<Type> generateWorstCaseArray(int size)
{
    std::vector<Type> v;
    std::generate_n(std::back_inserter(v),size,[size]() mutable {return size--;});
    return v;
}
