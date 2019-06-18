#include <stdio.h>
#include <stdlib.h>
#include "RADIX.h"

int getBiggest(int * A, int length){
    int i, biggest = A[0];
    for(i = 0; i<length; i++){
        if(A[i] > biggest)
            biggest = A[i];
    }
    return biggest;
}

int getDigits(int number)
{
    int temp, steps = 0;

    temp=number;

    while(temp)
    {
        temp=temp/10;
        steps++;
    }

    return steps;
}

void radixsort(int arr[], int n)
{
    int m = getBiggest(arr, n), i = 0, steps = 0;
    for (int exp = 1; m/exp > 0; exp *= 10){
        doCountingSort(arr, n, exp);
    }
}

void doCountingSort(int arr[], int length, int exp){
    int output[length]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < length; i++)
    {
        count[ (arr[i]/exp)%10 ]++;
    }
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = length - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    for (i = 0; i < length; i++)
    {
        arr[i] = output[i];
    }
}
