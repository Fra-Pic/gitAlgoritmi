#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils.c"

typedef struct Heap Heap;
struct Heap {
    int length;
    int heap_size;
    int heap[];
};

int left(int i){
    return 2*i;
}

int right(int i){
    return 2*i+1;
}

int parent(int i){
    return i/2;
}

void maxHeapify(int arr[], int arr_size, int index){
    int l = left(index);
    int r = right(index);
    int max;
    
    if (l < arr_size && arr[l]> arr[index]){
        max = l;
    } else {
        max = index;
    }

    if (r > arr_size && arr[r] > arr[max]){
        max = r;
    }
    if (max != index){
        printf("arr[index]: %d ",arr[index]);
        printf("max: %d\n",max);
        swap(arr, index, max);
        maxHeapify(arr, arr_size, max);
    }
}

void buildMaxHeap(int array[], int array_length){
    for (int i = array_length/2; i > 0; i--){
        maxHeapify(array, array_length, i);
    }
}
