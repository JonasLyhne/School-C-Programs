#include <stdio.h>
#include <stdlib.h>

void mergesort(int*,int,int);
void merge(int*,int,int,int);
int main()
{
    int array[] = {5,4,7,9,3,2,14,99,1};
    int *ptrArr = &array;
    int n = 9;

    printf("Unsorted Array:\n");
    for(int i=0;i<n;i++)
        printf("%d\n",*(ptrArr+i));

    mergesort(ptrArr,0,n-1);
    printf("Sorted Array:\n");
    for(int x=0;x<n;x++)
        printf("%d\n",*(ptrArr+x));

    return 0;
}

void mergesort(int *array, int min, int max)
{
    int mid;

    if(min < max)
    {
        mid = (min + max) / 2;
        mergesort(array, min, mid);
        mergesort(array, mid + 1, max);
        merge(array, min, mid, max);
    }
}

void merge(int *array,int min,int mid,int max)
{
    int i, mi, k, lo, temp[max+1];
    lo = min;
    i = min;
    mi = mid + 1;
    while ((lo <= mid) && (mi <= max))
    {
        if (*(array+lo) <= *(array+mi))
        {
            temp[i] = *(array+lo);
            lo++;
        }
        else
        {
            temp[i] = *(array+mi);
            mi++;
        }
        i++;
    }
    if (lo > mid)
    {
        for (k = mi; k <= max; k++)
        {
            temp[i] = *(array+k);
            i++;
        }
    }
    else
    {
        for (k = lo; k <= mid; k++)
        {
             temp[i] = *(array+k);
             i++;
        }
    }

    for (k = min; k <= max; k++)
    {
        *(array+k) = temp[k];
    }
}
