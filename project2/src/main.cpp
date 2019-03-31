#include "merge.hpp"
#include "quick.hpp"
#include "heap.hpp"
#include "random.hpp"
#include <iostream>
#include <vector>

int main()
{

    std::cout<<"MERGE:"<<std::endl;

    std::vector<int> v;
    v = generateWorstCaseArray<int>(10);


    for(unsigned int i = 0; i<v.size() ; ++i) std::cout<< v[i] << "\t";
    std::cout<<std::endl;

    mergeSort(v, 0, v.size() - 1);

    for(unsigned int i = 0; i<v.size() ; ++i) std::cout<< v[i] << "\t";
    std::cout<<std::endl;

/*
    std::cout<<"QUICK:"<<std::endl;

    int array2[] = {9,2,4,7,3,1,0,128};
    int arraySize2 = sizeof(array2)/sizeof(array2[0]);

    for(int i = 0; i<arraySize2 ; ++i) std::cout<< array2[i] << "\t";
    std::cout<<std::endl;

    quickSort(array2, 0, arraySize2 - 1);

    for(int i = 0; i<arraySize2 ; ++i) std::cout<< array2[i] << "\t";
    std::cout<<std::endl;
    */

/*
    std::cout<<"HEAP:"<<std::endl;

    int array3[] = {9,2,4,7,3,1,0,128};
    int arraySize3 = sizeof(array3)/sizeof(array3[0]);

    for(int i = 0; i<arraySize3 ; ++i) std::cout<< array3[i] << "\t";
    std::cout<<std::endl;

    heapSort(array3,arraySize3 - 1);

    for(int i = 0; i<arraySize3 ; ++i) std::cout<< array3[i] << "\t";
    std::cout<<std::endl;
*/
    return 0;
}
