#include <stdio.h>
#include "Node.c"


int sumNodes(struct Node *node){
    //caso base
    if (node == NULL){
        return 0;
    }
    /**
     * Sommo la chiave del nodo attuale poi scendo sia a sx che a dx
     */
    return (node -> key + sumNodes(node -> left) + sumNodes(node -> right));
}

int main(){
    struct Node *node = newTree();
    int final_sum = sumNodes(node);
    printf("final sum: %d", final_sum);
}