
#include <stdio.h>
#include "Node.c"
#include "../utils.c"

int search(int *in, int inStart, int inEnd, int data){
    for (int i = inStart; i < inEnd; i++){
        if (in[i] == data){
            return i;
        }
    }
}

struct Node *buildTreeFromInorderAndPreOrder(int *in, int*pre, int inStart, int inEnd, int preIndex){
    
    
    if (inStart > inEnd) return NULL;
    struct Node *new = newNode(pre[preIndex]);

    if (inStart == inEnd) return new;

    int inIndex = search(in, inStart, inEnd, new -> key);
    printf("in[%d]: %d, pre[%d]: %d\n", inIndex, in[inIndex], preIndex, pre[preIndex]);

    new -> left = buildTreeFromInorderAndPreOrder(in, pre, inStart, inIndex-1, preIndex+1);
    new -> right = buildTreeFromInorderAndPreOrder(in, pre, inIndex+1, inEnd, preIndex +1);

    return new;
}

int main(){
    int in[] = {10,20,25,27,30,37,40,44,45,50}; //inordine
    int pre[] = {30,25,20,10,27,40,37,45,44,50}; //preordine
    int size = 10;
    struct Node *node = buildTreeFromInorderAndPreOrder(in,pre,0,size-1,0);
    printNodes(node);
}