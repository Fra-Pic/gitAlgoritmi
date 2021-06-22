/**
 *   -----  Trova sottoalbero che contenga la somma indicata ---- 
You are given a binary tree and a given sum. The task is to check if there exist a subtree whose sum of all nodes is equal to the given sum.
*/
#include <stdio.h>
#include "Node.c"
#include "../utils.c"

int findSubTreeSum(struct Node *node, int given_sum, int *curr_sum){

    if (node == NULL) return 0;
    int s_left = 0;
    int s_right = 0;
    return findSubTreeSum( node -> left, given_sum, &s_left) 
    || findSubTreeSum(node -> right, given_sum, &s_right) 
    || ((*curr_sum = s_left + s_right + node -> key) == given_sum);
    
}

int findSubTreeSumUtility(struct Node *node, int given_sum){
    int curr_sum = 0;
    int res = findSubTreeSum(node, given_sum, &curr_sum);
    return res;
}

int main(){
    int root_value = 30;
    int values[] = {25,20,27,40,37,45,50,44,10};
    int size = 9;
    struct Node *node = newTreeFromVaues(root_value, values, size);
    int final = findSubTreeSumUtility(node, 328);
    printf("final sum tree: %d\n",final);
}