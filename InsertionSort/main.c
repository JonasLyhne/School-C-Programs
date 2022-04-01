#include <stdio.h>
#include <stdlib.h>

void insertionsort(int*, int);
int main()
{
    int array[] = {5,4,7,9,3,2,14,99,1};
    int *ptrArr = &array;
    int n = 9;

    printf("Unsorted Array:\n");
    for(int i=0;i<n;i++)
        printf("%d\n",*(ptrArr+i));

    insertionsort(ptrArr, n);
    printf("Sorted Array:\n");
    for(int x=0;x<n;x++)
        printf("%d\n",*(ptrArr+x));

    return 0;
}

void insertionsort(int *ptrArr, int n)
{
    for(int i=1; i<n; i++)
    {
        int value = *(ptrArr+i);

        int j = i-1;

        while(value<*(ptrArr+j)&&j>=0)
        {
            *(ptrArr+(j+1))=*(ptrArr+j);
            j--;
        }
        *(ptrArr+(j+1))=value;
    }
}
