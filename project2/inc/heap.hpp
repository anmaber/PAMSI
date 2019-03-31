#pragma once
#include <vector>

template <typename Type>
void heapify(std::vector<Type>& v, int size, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && v[left] > v[largest])
        largest = left;

    if (right < size && v[right] > v[largest])
        largest = right;

    if (largest != root)
    {
        std::swap(v[root], v[largest]);
        heapify(v, size, largest);
    }
}

template <typename Type>
void heapSort(std::vector<Type>& v, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(v, size, i);

    for (int i=size-1; i>=0; i--)
    {
        std::swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}
