
#include <stdio.h>
#include "Node.c"
#include "../utils.c"

int insertNode(struct Node *root, int val){
    if (root == NULL) return 0;

    if (root -> left == NULL && root -> key > val){
        printf("leaf node\n");
        root -> left = newNode(val);
    } else if (root -> right == NULL && root -> key < val){
        root -> right = newNode(val);
    }else {
        if (root -> key > val){
            insertNode(root -> left, val);
        }
        if (root -> key < val){
            insertNode(root -> right, val);
        }
    }
}

struct Node *_newTree(int *val, int size){
    struct Node *root = newNode(val[0]);
    for (int i = 1; i < size; i++){
        printf("inserting: %d\n", val[i]);
        insertNode(root, val[i]);
    }
    return root;
}

int main(){
    //int val[] = {10,20,25,27,30,37,40,44,45,50}; //inordine
    int val[] = {30,25,20,10,27,40,37,45,44,50}; //preordine
    int size = 10;
    struct Node *node = _newTree(val, size);
    printNodes(node);
}