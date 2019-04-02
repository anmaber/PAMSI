#pragma once

template <typename Type>
void heapify(Type* array, int size, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != root)
    {
        std::swap(array[root], array[largest]);
        heapify(array, size, largest);
    }
}

template <typename Type>
void heapSort(Type* array, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);

    for (int i=size-1; i>=0; i--)
    {
        std::swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}
