#pragma once

template <typename arrayType>
int partition (arrayType array[], int left, int right)
{
    int pivot = array[right];
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            arrayType temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    arrayType temp = array[i+1];
    array[i+1] = array[right];
    array[right] = temp;

    return (i + 1);
}


template <typename arrayType>
void quickSort(arrayType array[], int left, int right)
{
    if(left < right)
    {
        int pivot = partition(array,left,right);

        quickSort(array, left, pivot - 1);
        quickSort(array, pivot + 1, right);
    }
}
