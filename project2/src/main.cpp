#include "merge.hpp"
#include "quick.hpp"
#include <iostream>

int main()
{
    std::cout<<"MERGE:"<<std::endl;

    int array[] = {9,2,4,7,3,1,0,128};
    int arraySize = sizeof(array)/sizeof(array[0]);

    for(int i = 0; i<arraySize ; ++i) std::cout<< array[i] << "\t";
    std::cout<<std::endl;

    mergeSort(array, 0, arraySize - 1);

    for(int i = 0; i<arraySize ; ++i) std::cout<< array[i] << "\t";
    std::cout<<std::endl;

    std::cout<<"QUICK:"<<std::endl;

    int array2[] = {9,2,4,7,3,1,0,128};
    int arraySize2 = sizeof(array2)/sizeof(array2[0]);

    for(int i = 0; i<arraySize2 ; ++i) std::cout<< array2[i] << "\t";
    std::cout<<std::endl;

    quickSort(array2, 0, arraySize2 - 1);

    for(int i = 0; i<arraySize2 ; ++i) std::cout<< array2[i] << "\t";
    std::cout<<std::endl;


    return 0;
}
