/*
    Write a function that returns true if the given Binary Tree is SumTree else false. 
    A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. 
    An empty tree is SumTree and the sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.
*/
#include <stdio.h>
#include "Node.c"
#include "../utils.c"

int _sum (struct Node *node){
    if (node == NULL) return 0;
    return _sum(node -> left) + _sum(node -> right) + node -> key;
}

int checkSumTree(struct Node *node){
    if (node == NULL || (node -> right == NULL && node -> left == NULL)) return 1;

    int l = _sum(node -> left);
    int r = _sum(node -> right);

    if (l + r == node -> key && checkSumTree(node -> left) && checkSumTree(node -> right)){
        return 1;
    }
    return 0;
}

int main(){
    int root_value = 30;
    int values[] = {10,20};
    int size = 2;
    struct Node *node = newTreeFromVaues(root_value, values, size);
    int final = checkSumTree(node);
    printf("final sum tree: %d\n",final);
}