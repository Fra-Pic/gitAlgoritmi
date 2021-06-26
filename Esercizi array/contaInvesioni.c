#include <stdio.h>

/**
 * due elementi a[i] e a[j] sono un inversione se a[i] > a[j] e i < j
 * 
 * arr = {1,7,5,6}
 * 
 * ITERAZIONE 0
 * a[0] = 1
 * a[1] = 7
 * 1 < 7 & 0 < 1 - no inversione
 * 
 * -------------------------------
 * 
 * ITERAZIONE 1
 * a[1] = 7
 * a[2] = 5
 * 7 > 5 e 1 < 2 - inversione
 * 
*/

void printArray(int *arr, int arr_size){
    printf("arr size: %d\n",arr_size);
    for (int i = 0; i <arr_size; i++){
        if (i == arr_size - 1){
            printf("%d\n",arr[i]);
        } else {
            printf("%d, ",arr[i]);
        }
    }
}

int merge(int *arr, int left, int middle, int right){

    int n1 = middle - left + 1;
    int n2 = right - middle;
    int inv_count = 0;

    int LEFT[n1], RIGHT[n2];

    for (int i = 0; i < n1; i++){
        LEFT[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++){
        RIGHT[j] = arr[middle + j + 1];
    }
    LEFT[n1 + 1] = 10000;
    RIGHT[n2 + 1] = 10000;

    int left_index,right_index, index;
    right_index = left_index = 0;
    index = left;

    while(left_index < n1 && right_index < n2){
        if(LEFT[left_index] <= RIGHT[right_index]){
            arr[index] = LEFT[left_index];
            left_index++;
        } else {
            inv_count += (middle - left_index);
            arr[index] = RIGHT[right_index];
            right_index++;
        }
        index++;
    }

    while(left_index < n1){
        arr[index] = LEFT[left_index];
        index++;
        left_index++; 
    }

    while(right_index < n2){
        arr[index] = RIGHT[right_index];
        index++;
        right_index++; 
    }

    return inv_count;
}

int mergeSort(int *arr, int left, int right){
    int c = 0;
    if (left < right){
        int middle = left + (right - left)/2;
        c += mergeSort(arr, left, middle);
        c += mergeSort(arr, middle + 1, right);
        c += merge(arr, left, middle, right);
    }
    return c;
}

countInversioni(int *arr, int arr_size){
    //printArray(arr,arr_size);
    int c = mergeSort(arr, 0, arr_size - 1);
    printArray(arr, arr_size);
    printf("count: %d", c);
}

int main(){
    int arr_size = 4;
    int arr[] = {8,4,2,1};
    countInversioni(arr, arr_size);
}