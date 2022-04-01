#include <stdio.h>
#include <stdlib.h>

void selectionSort(int*, int);
int main()
{
    int array[] = {5,4,7,9,3,2,14,99,1};
    int *pArray = &array;
    int n = 9;

    printf("Unsorted Array:\n");
    for(int i=0;i<n;i++)
        printf("%d\n",*(pArray+i));

    selectionSort(pArray, n);
    printf("Sorted Array:\n");
    for(int x=0;x<n;x++)
        printf("%d\n",*(pArray+x));

    return 0;
}

void selectionSort(int *pArray, int length)
{
    //First index
    for(int i=0; i<length;i++)
    {
        int min_index = i;
        //Second index
        for(int j=i+1; j<length;j++)
        {
            //If value at min is greater j (the higher index)
            if(*(pArray+min_index)>*(pArray+j))
            {
                //Make value at min index switch with value at j index.
                int temp=*(pArray+min_index);
                *(pArray+min_index)=*(pArray+j);
                *(pArray+j)=temp;
            }
        }
    }
}

