#pragma once

template <typename arrayType>
void merge(arrayType A[], int begin, int mid, int end)
{
    int leftSize = mid - begin + 1;
    int rightSize = end - mid;

    arrayType left[leftSize];
    arrayType right[rightSize];

    for(int i = 0; i < leftSize; ++i) left[i] = A[begin+i];
    for(int i = 0; i < rightSize; ++i) right[i] = A[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = begin;

    while (i < leftSize && j < rightSize)
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

    while (i < leftSize)
    {
        A[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        A[k] = right[j];
        j++;
        k++;
    }
}


template <typename arrayType>
void mergeSort(arrayType A[], int begin, int end)
{
    if (begin < end)
    {
        int mid = begin + (end - begin)/2;

        mergeSort(A, begin, mid);
        mergeSort(A, mid + 1, end);

        merge(A, begin, mid, end);
    }
}
