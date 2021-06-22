#include <stdio.h>
#include <stdlib.h>

int countingSort(int arr[], int arr_size, int *b_arr, int range){
    int c_arr[range];
    printf("asdasdasdadadada\n");
    for (int i = 0; i <= range; i++){
        c_arr[i] = 0;
        
    }
    for (int j = 1; j <= arr_size; j++){
        c_arr[arr[j]] = c_arr[arr[j]] + 1;
    }
    printf("----------\n");
    for (int k = 1; k < 100; k++){
        //c_arr[i] = c_arr[i] + c_arr[i - 1];
    }
    /*for (int j = arr_size; j > 1; j--){
        b_arr[c_arr[arr[j]]] = arr[j];
        c_arr[arr[j]] = c_arr[arr[j]] - 1;
    }*/
}





/*bucketSort(int *arr, int size){
    int buffer[1000];
    int n = size;
    int empty_array[1000];

    for (int i = 0; i < n;  ++){
        buffer[i] = empty_array;
    }

    for (int i = 1; i <= n; i++){
        buffer[n*arr[i]] = arr[i];
    }

    for (int i = 0; i < n; i++){
        quickSort(buffer[i]);
    }

    
}*/