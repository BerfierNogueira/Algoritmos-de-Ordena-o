#include <stddef.h>
#include "utils.h"

int arrayLength(int arr[]){
    return sizeof(arr)/sizeof(arr[0]);
}

void copy(int arr[], int destiny[], int stop){
    int i =0;
    for(i; i<stop; i++){
        destiny[i] = arr[i];
    }
}
