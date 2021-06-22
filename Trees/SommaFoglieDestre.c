#include <stdio.h>
#include "Node.c"

int isLeaf(struct Node *node){
    if (node -> left == NULL && node -> right == NULL){
        return 1;
    }
    return 0;
}

int sumRightLeaves(struct Node *node){
    int sum = 0;

    if (node == NULL){
        return 0;
    }
    
    if (node != NULL){

        if (node -> right != NULL && isLeaf(node -> right) == 1){
            sum += node -> right -> key;
        }

        sum += sumRightLeaves(node -> left);
        sum += sumRightLeaves(node -> right);
    }
    return sum;
}


int main(){
    struct Node *node = newTree();
    int final_sum = sumRightLeaves(node);
    printf("final sum: %d", final_sum);
}