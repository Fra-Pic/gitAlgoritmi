#include <stdio.h>
#include "Node.c"
#include "../Queue/queue.c"


int findLongestPath(struct Node *node, int sum, int len, int maxSum, int maxLen){

    if (node == NULL){
        if (maxLen < len){
            maxLen = len;
            maxSum = sum;
        }else if (maxLen == len && maxSum < sum){
            maxSum = sum;
        }
        return 0;
    }

    findLongestPath(node -> left, sum + node -> key, len++, maxSum, maxLen);
    findLongestPath(node -> right, sum + node -> key, len++, maxSum, maxLen);
}

int findLongestRootToLeafPathUtil(struct Node *node){
    int sum = 0, len = 0, maxSum = INT_MIN, maxLen = 0;
    int res = findLongestPath(node, sum, len, maxSum, maxLen);
    return maxSum;
}


int main(){
    int root_value = 30;
    int values[] = {25,20,27,40,37,45,50,44,10};
    int size = 9;
    struct Node *node = newTreeFromVaues(root_value, values, size);

    int res = findLongestRootToLeafPathUtil(node);
    //printf("Longest path: %d", res);
}