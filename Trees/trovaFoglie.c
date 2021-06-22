#include <stdio.h>
#include "Node.c"

int findLeaves(struct Node *node){
    if (node == NULL){
        return 0;
    }
    //foglia
    if (node -> left == NULL && node -> right == NULL){
        printf("%d ",node -> key);
        return 0;
    }
    return findLeaves(node -> left) + findLeaves(node -> right);
}

int main(){
    struct Node *Tree = newNode(5);
    printf("Node key: %d\n", Tree -> key);
    int size = 8;
    int values[] = {10,9,6,4,12,7,11,1};
    struct Node *populated_tree = populateTree(Tree, values, size);
    printNodes(populated_tree);
    printf("\n");
    findLeaves(populated_tree);
}