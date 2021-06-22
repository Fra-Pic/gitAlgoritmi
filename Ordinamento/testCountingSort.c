#include <stdio.h>
#include "../binary_trees/Node.c"
#include "../utils.c"
#include "countingSort.c"

int main(){
    int values[] = {30,25,20,27,40,40,45,50,44,10};
    int size = 10;
    int val[10] = {0,0,0,0,0,0,0,0,0,0};
    int index = 0;

    countingSort(values, 10, val, 100);
}