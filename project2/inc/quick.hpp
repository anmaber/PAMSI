#pragma once

template <typename Type>
int partition (Type* array,int left,int right)
{
    int pivot = array[right];
    int m = left;


    for(int i =left; i <= right -1;++i)
    {
        if(array[i] <= pivot)
        {
            std::swap(array[i],array[m]);
            m++;
        }

    }
    std::swap(array[right],array[m]);

    return m;
}

template <typename Type>
void quickSort (Type* array,int left,int right)
{
    if(left<right)
    {
        int tmp = partition(array, left, right);

        quickSort(array,left,tmp-1);
        quickSort(array,tmp+1,right);
    }
}
