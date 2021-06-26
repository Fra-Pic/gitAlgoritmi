#include <stdlib.h>
#include <stdio.h>
#include "../utils.c"

int partition(int *arr, int left, int right){
   int pivot = arr[right];
   int index = left-1;

   for (int i = left; i < right; i++){
       if (arr[i] <= pivot){
           index++;
           _swap(&arr[i], &arr[index]);
       }
   } 
   _swap(&arr[index+1], &arr[right]);
   return index+1;;
}

int quickSort(int *arr, int left, int right){
    if (left < right){
        int mid = partition(arr, left, right);
        printf("qqq\n");
        quickSort(arr, left, mid - 1);
        quickSort(arr, mid + 1, right);
    }
}

int searchNearest(int *arr, int index, int arr_size, int val){
    if (index > arr_size){
        return 0;
    }
    if (arr[index] >= val){
        return arr[index];
    } else{
        if (arr[index] < val){
            searchNearest(arr, index + 1, arr_size, val);
        } else {
            searchNearest(arr, index + 2, arr_size, val);
        }
    }
}

int findPairs(int *X, int size_x, int *Y, int size_y){
    quickSort(Y, 0, size_y);
    printArray(Y, size_y);

    int count = 0;
    for (int i  = 0; i < size_x; i++){
        int nearest = searchNearest(Y, 0, size_y, X[i]);
        printf("nearest: %d\n", nearest);
        int xpow = pow(X[i], nearest);
        int ypow = pow(nearest, X[i]);
        printf("%d %d\n",xpow, ypow);
        if (xpow > ypow){
            count++;
        }
    }

    return count;
}

int main(){

    int X[] = {2,1,6};
    int Y[] = {1,5};

    int X_SIZE = 3;
    int Y_SIZE = 2;

    int pairs = findPairs(X, X_SIZE, Y, Y_SIZE);
    printf("pairs: %d",pairs);
}