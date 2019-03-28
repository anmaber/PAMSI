#include "merge.hpp"
#include <iostream>

int main()
{

    int array[] = {9,2,4,7,3,1,0,128};
    int arraySize = sizeof(array)/sizeof(array[0]);

    for(int i = 0; i<arraySize ; ++i) std::cout<< array[i] << "\t";
    std::cout<<std::endl;

    mergeSort(array, 0, arraySize - 1);

    for(int i = 0; i<arraySize ; ++i) std::cout<< array[i] << "\t";
    std::cout<<std::endl;


    return 0;
}
