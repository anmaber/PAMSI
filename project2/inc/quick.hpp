#pragma once
#include <vector>
#include <cstdlib>

int choosePivot(int left , int right)
{
    div_t result = div((left+(right-1)),2);

    return result.quot;
}


template <typename Type>
int partition (std::vector<Type>& v,int left,int right)
{
    int centerElement = choosePivot(left, right);
    int Pivot = v[centerElement];

    std::swap(v[centerElement],v[right]);

    int actualPosition = left;

    for(int i=left;i<=right-1;i++)
    {
        if(v[i]<Pivot)
        {
            std::swap(v[actualPosition],v[i]);
            actualPosition++;
        }
    }

    std::swap(v[actualPosition],v[right]);

    return actualPosition;
}

template <typename Type>
void quickSort (std::vector<Type>& v,int left,int right)
{
    if(left<right)
    {
        int tmp = partition(v, left, right);

        quickSort(v,left,tmp-1);
        quickSort(v,tmp+1,right);
    }
}
