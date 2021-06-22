#include <stdio.h>
#include <stdlib.h>

#include "./node.c"
#include "./queue.c"


void enqueueLevel(struct Node *root, struct Queue *q){
    if (root -> left != NULL){
        enqueue(q, root -> left -> key);
    }
    if (root -> right != NULL){
        enqueue(q, root -> right -> key);
    }
};

int main(){

    struct Node *root = newNode(50);
    int SIZE = 10;
    int values[] = {23,37,60,94,12,55,17,82,4,71};
    insertArrayToTree(root, values, SIZE);
/*
    struct Node *exactNode = findNode(root, 71);
    int level = 0;
    level = findNodeLevel(root, 1, exactNode -> key);
    if (exactNode != NULL){ 
        printf("\nfindNode - Found node with key: %d\n",exactNode ->key);
        printf("findNodeLevel - Node is at level: %d\n", level);
    } else {
        printf("Node Not Found\n");
    }
*/
    //printf("\nroot: %d, left: %d, right: %d\n",root -> key, root -> left -> key, root -> right -> key);
    struct Queue *queue = newQueue(10);
    //struct NodeQueue *nodeQueue = newNodeQueue(10);
    //nodeEnqueue(nodeQueue, exactNode);
    
    //insertArrayToQueue(queue, values, SIZE);
    //dequeueArray(queue);
    int h = getHeight(root, 0);
    printf("HEIGHT: %d\n",h);
    printTreeByLevel(root);
    deleteValue(root, 55);
    printTreeByLevel(root);
    //printTreeByLevel(root);
}