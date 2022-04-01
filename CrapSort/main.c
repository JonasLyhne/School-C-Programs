#include <stdio.h>
#include <stdlib.h>

// This does not work, and was a playground project for som pointer stuff

int main()
{

    int xVals[]  = {3,1,5,2,4};
    int* x = xVals;
    int xLength = sizeof(xVals)/sizeof(int);
    int zVals[xLength];
    int* z = zVals;
    int yVals[xLength];
    int* y = yVals;
    int rVals[xLength];
    int* r = rVals;


    printf("Unsorted array: ");
    printNumArray(x, 5);

    crapSort(x, xLength, z, y, r);
    int in;
    /*for(in = 0; in < xLength; in++)
    {
        printf("%d : ", rVals[in]);
    }*/
    printf("Sorted array (totally): ");
    printNumArray(r, 5);

    return 0;
}

void crapSort(int* x, int xLength, int* z, int* y, int* r) {

    //int xLength = sizeof(x)/sizeof(int);

    int currentYIndex;
    int currentZIndex;
    int currentRIndex = 0;
    int count = xLength;


    while(count != 0) {
        currentYIndex = 0;
        currentZIndex = 0;

        for(int i = 0; i < xLength; i++) {

            int xVal = pop(&x);
            printf("CurrentX: %d \n", xVal);

            // The first element from X should always be put on Y.
            if(i == 0) {
                y[currentYIndex] = xVal;
                currentYIndex++;
                continue;
                // If the current value from X is larger than the top of Y. Put it on top of Y.
            } else if (xVal > y[currentYIndex]){
                y[currentYIndex] = xVal;
                currentYIndex++;
            } else { // If the current value from X is less than the top of Y. Put it on top of Z.
                z[currentZIndex] = xVal;
                currentZIndex++;
            }

        }

        r[currentRIndex] = y[currentYIndex-1]; // currentYIndex-1 at this point is the last element put in Y.

        currentRIndex++;

        printf("currentR: %d \n", r[currentRIndex]);

        //x = y + z;
        // Y Length = currentYIndex + 1
        // Z Length = currentZIndex +1
        int newXLength = (currentYIndex) + (currentZIndex);
        printf("newX: %d \n", newXLength);
        //free(x);
        printf("freedX \n");
        x = malloc(sizeof(int)*newXLength+1); // Size of int, + num elements + null terminator.
        merge(y, currentYIndex-1, z, currentZIndex, x);


        count--;

    }
    return 0;
}

void printNumArray(int* arr, size_t numElements) {
    for(int i = 0; i < numElements; i++) {
        printf("%d,", arr[i]);
    }

    printf("\n");
}

int pop(int** subject) {
    int val = **subject;
    (*subject)++;
    return val;
}

void merge(int *a, int m, int *b, int n, int *c)
{
    int i=0,j=0,k=0;
    // Merging the two arrays
    while(i<m && j<n){
        if(a[i] < b[j]){
            c[k] = a[i]; i++;
        }else{
            c[k] = b[j]; j++;
        }
        k++;
    }
    // Elements left in first array
    if(i<m)
        while(i<m){
        c[k] = a[i]; i++; k++;
        }
    // Elements left in second array
    else
        while(j<n){
            c[k] = b[j]; j++; k++;
        }
}


