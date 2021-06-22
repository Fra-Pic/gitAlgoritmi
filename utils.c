#include <stdio.h>
#include <stdlib.h>

void swap(int array[], int a, int b){
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
    printf("swapped: %d %d\n",array[a],array[b]);
} 

void printArray(int array[], int length){
    printf("Array: \n");
    for (int i = 0; i < length; i++){
        if (i == length - 1){
            printf("%d\n",array[i]);
        } else {
            printf("%d,",array[i]);
        }
    }
    printf("\n");
}

int max(int a, int b){
    return a > b ? a : b;
}