#pragma once
#include <vector>
#include <cstdlib>
/*
int choosePivot(int left , int right)
{
    div_t result = div((left+(right-1)),2);

    return result.quot;
}

*/
template <typename Type>
int partition (Type* v,int left,int right)
{
    int pivot = v[right];
    int m = left;


    for(int i =left; i <= right -1;++i)
    {
        if(v[i] <= pivot)
        {
            std::swap(v[i],v[m]);
            m++;
        }

    }
    std::swap(v[right],v[m]);

    return m;
    /*
    int centerElement = choosePivot(left, right);
    int Pivot = v[centerElement];

    Type tmp = v[right];
    v[right]= v[centerElement];
    v[centerElement] = tmp;
    //std::swap(v[centerElement],v[right]);

    int actualPosition = left;

    for(int i=left;i<=right-1;i++)
    {
        if(v[i]<Pivot)
        {
            //std::swap(v[actualPosition],v[i]);
            Type tmp = v[i];
            v[i]= v[actualPosition];
            v[actualPosition] = tmp;
            actualPosition++;
        }
    }

    //std::swap(v[actualPosition],v[right]);
    Type tmp2 = v[right];
    v[right]= v[actualPosition];
    v[actualPosition] = tmp2;

    return actualPosition;
    */
}

template <typename Type>
void quickSort (Type* v,int left,int right)
{
    if(left<right)
    {
        int tmp = partition(v, left, right);

        quickSort(v,left,tmp-1);
        quickSort(v,tmp+1,right);
    }
}
