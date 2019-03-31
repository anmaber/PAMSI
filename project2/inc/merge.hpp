#pragma once
#include <vector>

template <typename arrayType>
void merge(std::vector<arrayType>& A, int begin, int mid, int end)
{
    int leftSize = mid - begin + 1;
    int rightSize = end - mid;

    std::vector<arrayType> left;
    left.resize(leftSize);
    std::vector<arrayType> right;
    right.resize(rightSize);

    for(unsigned int i = 0; i < left.size(); ++i) left[i] = A[begin+i];
    for(unsigned int i = 0; i < right.size(); ++i) right[i] = A[mid + 1 + i];

    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = begin;

    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
        {
            A[k] = left[i];
            i++;
        }
        else
        {
            A[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left.size())
    {
        A[k] = left[i];
        i++;
        k++;
    }

    while (j < right.size())
    {
        A[k] = right[j];
        j++;
        k++;
    }
}


template <typename arrayType>
void mergeSort(std::vector<arrayType>& A, int begin, int end)
{
    if (begin < end)
    {
        int mid = begin + (end - begin)/2;

        mergeSort(A, begin, mid);
        mergeSort(A, mid + 1, end);

        merge(A, begin, mid, end);
    }
}
