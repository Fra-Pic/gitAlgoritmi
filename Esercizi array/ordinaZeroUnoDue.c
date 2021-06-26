#include <stdlib.h>
#include <stdio.h>
#include "../utils.c"

int reorderZeros(int *arr, int size){
    int min, mid,max;

    min = mid = 0;
    max = size - 1;
    while(mid < max){
        if (arr[mid] == 0){
            _swap(&arr[mid++], &arr[min++]);
        } else if (arr[mid] == 1){
            mid++;
        } else if (arr[mid] == 2){
            _swap(&arr[mid++], &arr[max--]);
        }
    }
}

int main(){
    int arr[] = {0,0,0,1,1,1,0,0,1,2};
    int size = 10;

    reorderZeros(arr, size);
    printArray(arr, size);
}