/*   MERGESORT  */
#include <stdio.h>

int merge(int *arr, int left, int middle, int right){
    int index_left, index_right;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int LEFT[n1], RIGHT[n2];

    for (int i = 0; i < n1; i++){
        LEFT[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++){
        RIGHT[i] = arr[middle + i + 1];
    }

    index_left = 0;
    index_right = 0;
    int k;

    for (int k = left; k <= right; k++){
        if (LEFT[index_left] > RIGHT[index_right]){
            arr[k] = LEFT[index_left];
            index_left = index_left + 1;
        } else {
            arr[k] = RIGHT[index_right];
            index_right = index_right + 1;
        }
    }

}

int mergeSort(int *arr, int left, int right){
    if (right > left){
        int middle = left + (right - left)/2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}