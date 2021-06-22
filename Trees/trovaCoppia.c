#include <stdio.h>
#include "Node.c"
#include "../Queue/queue.c"

int findCoupleInPath(struct Node *root){
    int mid_value = 0;
    struct Node *iter = root;

    while (iter != NULL){
        if (iter -> left == NULL && iter -> right == NULL){
            if (iter -> key + mid_value == root -> key){
                printf("Sum between %d and %d equals: %d", iter ->key, mid_value, iter ->key + mid_value);
                return 1;
            }
        }
    }
}

int findCoupleUtil(struct Node *root){

    if (root == NULL) return 0;
    findCoupleUtil(root -> left);
    findCoupleUtil(root -> right);
    printf("node: %d\n", root -> key);
}

int main(){
    int root_value = 30;
    int values[] = {25,20,27,40,37,45,50,44,10};
    int size = 9;

    struct Node *node = newTreeFromVaues(root_value, values, size);
    //int final_sum = findCoupleUtil(node);
    struct Queue *queue = newQueue(10);
    enqueue(queue, 111);
    enqueue(queue, 23);
    enqueue(queue, 34);
    enqueue(queue, 56);
    enqueue(queue, 9);

    //printf("final sum: %d", final_sum);
}