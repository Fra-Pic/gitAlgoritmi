/**
 *   -----  Trova sottoalbero con somma maggiore ---- 
 Do post order traversal of the binary tree. 
 At every node, find left subtree value and right subtree value recursively. 
 The value of subtree rooted at current node is equal to sum of current node value, left node subtree sum and right node subtree sum. 
 Compare current subtree sum with overall maximum subtree sum so far.
*/
#include <stdio.h>
#include "Node.c"
#include "../Queue/queue.c"

int max(int a, int b){
    return a > b ? a : b;
}

int findSubTree(struct Node *node, int cur_sum, int *max_sum){
    if (node == NULL) return 0;
    
    cur_sum = node -> key + findSubTree(node -> left, cur_sum, max_sum) + findSubTree(node -> right, cur_sum, max_sum);
    
    *max_sum = max(cur_sum, *max_sum);
    return cur_sum;
}

int findSubTreeUtil(struct Node *node){
    int cur_sum = 0;
    int max_sum = INT_MIN;

    findSubTree(node, cur_sum, &max_sum);
    return max_sum;
}

int main(){
    int root_value = 30;
    int values[] = {25,20,27,40,37,45,50,44,10};
    int size = 9;
    struct Node *node = newTreeFromVaues(root_value, values, size);
    int final = findSubTreeUtil(node);
    printf("final sum tree: %d\n",final);
}