#pragma once
#include <vector>

template <typename Type>
int partition (std::vector<Type>& v, int left, int right)
{
    int pivot = v[right];
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++)
    {
        if (v[j] <= pivot)
        {
            i++;
            std::swap(v[i],v[j]);
        }
    }
    std::swap(v[i+1],v[right]);

    return (i + 1);
}


template <typename Type>
void quickSort(std::vector<Type>& v, int left, int right)
{
    int pivot =0;
    if(left < right)
    {
        pivot = partition(v,left,right);

        quickSort(v, left, pivot - 1);
        quickSort(v, pivot + 1, right);
    }
}
