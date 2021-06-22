/*   QUICKSORT  */
#include <stdio.h>

int partition(int *arr, int left, int right){
    int pivot = arr[right];
    int index = left - 1;

    for (int j = left; j < right; j++){
        if (arr[j] <= pivot){
            index = index + 1;
            swap(arr, j, index);
        }
    }
    swap(arr, index + 1, right);
    return index + 1;
}

int quickSort(int *arr, int left, int right){
    if (right > left){
        int middle = partition(arr, left, right);
        quickSort(arr, left, middle - 1);
        quickSort(arr, middle + 1, right);
    }
}