#include <stdio.h>
#include "Node.c"
#include "../Queue/queue.c"
#include "../utils.c"
#include "../Array/Array.c"
#include "../Ordinamento/mergeSort.c"
#include "../Ordinamento/quickSort.c"
#include "../Ordinamento/countingSort.c"


int checkDuplicates(struct Node *node, struct Array *arr){

    if (node == NULL) return 0;
    checkDuplicates( node -> left, arr);
    
    checkDuplicates(node -> right, arr);
    push(arr, node -> key);
    
}

int main(){
    int root_value = 30;
    int values[] = {25,20,27,40,40,45,50,44,10};
    int size = 9;
    struct Node *node = newTreeFromVaues(root_value, values, size);

    int val[10] = {0,0,0,0,0,0,0,0,0,0};
    struct Array *to_be_analized = newArray(&val, 0);
    int index = 0;
    printArrayValues(to_be_analized);
    int res = checkDuplicates(node, to_be_analized);
    printArrayValues(to_be_analized);

    /*mergeSort(values, 0, 10);
    printf("\n");
    printArrayValues(to_be_analized);*/

    /*quickSort(values, 0, 10);
    printf("\n");
    printArrayValues(to_be_analized);*/
    countingSort(to_be_analized -> items, 10, val, 100);
    //printf("duplicated found: %d",res);
}