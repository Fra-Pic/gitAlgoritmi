#include <stdio.h>
#include "Node.c"

int sumParentWithChild(struct Node *node,int key){

    if (node == NULL){
        return 0;
    }

    int r = 0;
    if ((node -> left && node -> left -> key == key) || (node -> right && node -> right -> key == key)){
        r = r + node -> key;
    }
    r = r + sumParentWithChild(node -> left,key);
    r = r + sumParentWithChild(node -> right,key);
    printf("r: %d\n",r);
    return r;
    //printf("\t%d]\tsum: %d\n",index,sum);
    //return sum;
}

int sumP(struct Node *node, int key){
    int sum = sumParentWithChild(node, key);
    return sum;
}
int main(){
    struct Node *node = newTree();
    int final_sum = sumP(node,7);
    printf("final sum: %d", final_sum);
}