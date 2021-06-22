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

int findSumFinal(struct Node *node, struct Node **buffer, int *max_sum, int curr_sum){
    if (node == NULL) return 0;
    curr_sum = curr_sum + node -> key;

    /* e' una foglia? 
        se lo è e la somma corrente è > di quella massima, quella massima diventa la corrente e il buffer diventa la nuova foglia
        lo usiamo per printare poi il percorso tra root e foglia con percorso massimo
    */
    if (node -> left == NULL && node -> right == NULL){
        if (curr_sum > *max_sum){
            *max_sum = curr_sum;
            *buffer = node;
        }
    }

    findSumFinal(node -> left, buffer, max_sum, curr_sum);
    findSumFinal(node -> right, buffer, max_sum, curr_sum);
}

int findSumPath(struct Node *node){
    if (node == NULL){
        return 0;
    }

    int max_sum = INT_MIN;
    int curr_sum = 0;
    struct Node *buffer;
    findSumFinal(node, &buffer, &max_sum, curr_sum);
    printPath(node, buffer);
    return 1;
}

int main(){
    int root_value = 30;
    int values[] = {25,20,27,40,37,45,50,44,10};
    int size = 9;
    struct Node *node = newTreeFromVaues(root_value, values, size);
    findSumPath(node);
}