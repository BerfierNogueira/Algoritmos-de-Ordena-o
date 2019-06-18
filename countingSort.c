#include "countingSort.h"
#include "stdio.h"

int * countingSort(int arr[], int size){
    int i, j, biggest = 0;
    for(i = 0; i<size; i++){
        printf("%d ", arr[i]);
        if(arr[i] > biggest)
            biggest = arr[i];
    }
    printf("\n");
    int C[biggest+1], result[size];
    for(i = 0; i <= biggest; i++){
        C[i] = 0;
    }
    for(j = 0; j<size; j++){
        C[arr[j]] += 1;
    }

    for(i = 1; i<=biggest; i++){
        C[i] = C[i] + C[i-1];
    }

    for(j = size-1; j >= 0; j--){
        result[C[arr[j]]] = arr[j];
        C[arr[j]]--;
    }

    int eps;
    for(eps = 1; eps <= size; eps++){
        arr[eps-1] = result[eps];
    }
    return arr;
}

