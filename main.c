#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "countingSort.h"
#include "RADIX.h"
#include "utils.h"
#include "BubbleSort.h"
#include "quicksort.h"
#include "bucketSort.h"

#define length(x) sizeof(x)/sizeof(x[0])

int main(){
    const int maker[] = {
    22, 92, 40, 17, 96, 15, 24, 80, 90, 57, 93, 111, 14, 86, 10, 82, 31, 100, 3, 98, 7, 11, 97, 154, 69, 54, 2, 87, 42, 50, 88, 79, 44, 13, 26, 121, 39, 8, 30, 83, 49, 53, 55, 94, 3, 70, 19, 68, 59, 38, 21, 81, 9, 18, 72, 25, 84, 41, 74, 32, 4, 55, 45, 1,20, 37, 45, 6, 65, 56, 91, 47, 58, 43, 99, 61, 51, 85, 35, 48,29, 60, 14, 75, 23, 5, 63, 64, 71, 78, 77, 27, 76, 10, 46, 89,73, 34, 12, 33, 16, 28, 95, 67, 62, 66, 88, 52, 2, 36, 0, 21, 139, 149, 175, 160, 130, 174, 188, 159, 140, 180, 128, 178, 135, 126, 138, 143, 187, 179, 191, 157, 185, 177, 161, 147, 184, 169, 162, 192, 155, 152, 136, 171, 132, 127, 150, 122, 181, 142,124, 123, 196, 121, 168, 146, 141, 137, 131, 145, 120, 148, 134, 176, 167, 158, 182, 190, 173, 193, 165, 195, 133, 170, 197, 156, 183, 194, 199, 129, 186, 166, 154, 151, 172, 163, 189, 164, 125, 153, 144, 198
    };
    int A[length(maker)]; //for counting sort
    int B[length(maker)]; //for RADIX Sort
    int C[length(maker)]; //for bubble sort
    int D[length(maker)]; //for quick sort
    int E[length(maker)]; //for bucket sort
    int F[length(maker)]; //for heap sort
    copy(maker, A, length(maker));
    copy(maker, B, length(maker));
    copy(maker, C, length(maker));
    copy(maker, D, length(maker));
    copy(maker, E, length(maker));
    copy(maker, F, length(maker));

    printf("\nTamanho de A[]: %d\n\n", length(A));
    printf("Usando Counting Sort:\n");
    clock_t t;
    t = clock();

    int * x = countingSort(A, length(A)); //Parte do counting sort
    printf("\nConjunto A: ");
    for(int i = 0; i<length(A);i++){
        printf("%d ", x[i]);
    }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("\nCounting sort levou %f segundos para ser executado\n\n", time_taken);

    /*
    ---------------------------------------------------------------------------------
    */
    printf("Radix: \n");
    t = clock();
    radixsort(B, length(B));
    for(int i = 0; i<length(B);i++){
        printf("%d ", B[i]);
    }
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("\nRadix sort levou %f segundos para ser executado\n", time_taken);

    /*
    ---------------------------------------------------------------------------------
    */

    printf("\nBubble Sort: \n");
    t = clock();
    bubble_sort(C, length(C));
    for(int i = 0; i<length(C);i++){
        printf("%d ", C[i]);
    }
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("\nBubble sort levou %f segundos para ser executado\n", time_taken);


    /*
    ---------------------------------------------------------------------------------
    */

    printf("\n\nQuick Sort: \n");
    t = clock();
    Quick(D, 0, length(D));
    for(int i = 0; i<length(D);i++){
        printf("%d ", D[i]);
    }
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("\nQuick sort levou %f segundos para ser executado\n", time_taken);


    /*
    ---------------------------------------------------------------------------------
    */

    /*
    printf("\n\Bucket Sort: \n");
    printf("\nLength E = %d", length(E));
    for(int i = 0; i<length(E);i++){
        E[i] = 0;
    }

    copy(maker, E, length(maker));

    t = clock();
    Bucket_Sort(E, length(E));
    for(int i = 0; i<length(E);i++){
        printf("%d ", E[i]);
    }
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("\nBucket sort levou %f segundos para ser executado\n", time_taken);
    */

    /*
    ---------------------------------------------------------------------------------
    */

    printf("\n\HeapSort: \n");
    t = clock();
    heapsort(F, length(F));
    for(int i = 0; i<length(F);i++){
        printf("%d ", F[i]);
    }
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("\Heapsort levou %f segundos para ser executado\n", time_taken);


    /*
    ---------------------------------------------------------------------------------
    */
}
