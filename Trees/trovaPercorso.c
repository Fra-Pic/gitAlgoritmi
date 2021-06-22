#include <stdio.h>
#include "Node.c"

int printSubPaths(struct Node *node){
    
    if (node == NULL){
        return 0;
    }

    //foglia
    if (node -> left == NULL && node -> right == NULL){
        printf("%d \n",node -> key);
        return 0;
    }
    printf("%d ",node -> key);

    int sub = printSubPaths(node -> left) + printSubPaths(node -> right);
    
}

void findPath(struct Node *node, int key){
    printf("key to find: %d\n", key);
    if (node -> key == key){
        printSubPaths(node -> left) + printSubPaths( node -> right);
    } else {
        if (node -> key > key){
            findPath(node -> left, key);
        } else {
            findPath(node -> right, key);
        }
    }
}

int main(){
    struct Node *Tree = newNode(5);
    int size = 8;
    int values[] = {10,7,6,4,12,9,11,1}; //invert 7 e 9
    struct Node *populated_tree = populateTree(Tree, values, size);
    printNodes(populated_tree);
    printf("\n");
    findPath(populated_tree, 5);
}