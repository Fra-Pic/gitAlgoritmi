#include <stdio.h>
#include "Node.c"
#include "../Queue/queue.c"

int printPath(struct Node* root, struct Node* target_leaf)
{
    if (root == NULL)
        return 0;
    if (root == target_leaf || printPath(root->left, target_leaf) || printPath(root->right, target_leaf)) {
        printf("data: %d\n", root -> key);
        return 1;
    }
    return 0;
}

int main(){
    int root_value = 30;
    int values[] = {25,20,27,40,37,45,50,44,10};
    int size = 9;
    struct Node *node = newTreeFromVaues(root_value, values, size);
    int key = 10;
    struct Node *res = getNode(node, key);
    if (res != NULL){
        printPath(node, res);
        printf("Found node: %d\n", res -> key);
    } else {
        printf("Node %d not found.\n", key);
    }
}