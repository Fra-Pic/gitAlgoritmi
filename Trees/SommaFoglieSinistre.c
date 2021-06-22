#include <stdio.h>
#include "Node.c"

int isLeaf(struct Node *node){
    if (node == NULL){
        return 0;
    }
    if (node -> left == NULL && node -> right == NULL){
        return 1;
    }
    return 0;
}

int countLeaves(struct Node *node){

    if (node == NULL){
        return 0;
    } else {
        int r= 0;
        if (isLeaf(node -> left) == 1){
            r = r + node -> left -> key;
            printf("node: %d, sum: %d\n", node -> key);
        } else {
            r = r + countLeaves(node -> left);
        }
        r = r + countLeaves(node -> right);
        return r;
    }
}

int sumLeftLeaves(struct Node *node){
    int l = countLeaves(node);
    return l;
}

int main(){
    struct Node *node = newTree();
    int left_leaves = sumLeftLeaves(node);
    printf("final left leaves sum: %d", left_leaves);
}