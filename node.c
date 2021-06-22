#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} * Node;

struct Node *newNode(int value){
    struct Node *new = malloc(sizeof(struct Node));
    new -> left = NULL;
    new -> right = NULL;
    new -> parent = NULL;
    new -> key = value;
    return new;
}

int getHeight(struct Node *node, int height){
    if (node == NULL) return 0;
    if (node -> left == NULL && node -> right == NULL) {
        return 1;
    }

    return getHeight(node -> left, height + 1) + getHeight(node -> right, height + 1);
}

int printTreeAtLiv(struct Node *node, int level){
    if (node == NULL) return 0;
    if (level == 1){
        printf("%d ",node -> key);
    } else {
        printTreeAtLiv(node -> left, level - 1);
        printTreeAtLiv(node -> right, level - 1);
    }
}

int printTreeByLevel(struct Node *node){
    int h = getHeight(node,0);
    for (int i = 0; i <= h; i++){
        printTreeAtLiv(node, i);
        printf("\n");
    }
}

void printTree(struct Node *root, char *traverse_type){
    if (traverse_type == "preorder"){
        printf("%d ", root ->key);
        if (root -> left != NULL) printTree(root -> left, traverse_type);
        if (root -> right != NULL) printTree(root -> right, traverse_type);
    }
    else if (traverse_type == "inorder"){
        if (root -> left != NULL) printTree(root -> left, traverse_type);
        printf("%d ", root ->key);
        if (root -> right != NULL) printTree(root -> right, traverse_type);
    }
    else if (traverse_type == "postorder"){
        if (root -> left != NULL) printTree(root -> left, traverse_type);
        if (root -> right != NULL) printTree(root -> right, traverse_type);
        printf("%d ", root ->key);
    }
}

struct Node *findSuccessore(struct Node *node){
    if (node == NULL) return 0;
    if (node -> right != NULL){
        if (node -> right -> left != NULL){
            return node -> right -> left;
        } else {
            return node -> right;
        }
    } else {
        if (node -> left != NULL) return node -> left;
        return NULL;
    }
}

struct Node *minVal(struct Node *node){
    struct Node *c = node;
    while (c && c -> left != NULL){
        c = c -> left;
    }
    return c;
}

struct Node *deleteValue(struct Node *node, int key){
    if (node == NULL) return 0;

    if (node -> key < key){
        deleteValue(node -> right, key);
    } else if (node -> key > key){
        deleteValue(node -> left, key);
    } else {
        if (node -> left == NULL){
            struct Node *prev = node -> right;
            free(node);
            return prev;
        }
        if (node -> right == NULL){
            struct Node *prev = node -> left;
            free(node);
            return prev;
        }
        struct Node *prev =  minVal(node -> right);
        node -> key = prev -> key;
        node -> right = deleteValue(node -> right, prev -> key);
    }
}

void insertValue(struct Node *root, struct Node *new){
    
    if (root -> left == NULL && root ->key > new -> key){
        root -> left = new;
        return;
    }
    if (root -> right == NULL && root ->key <= new -> key){
        root -> right = new;
        return;
    }

    if (root -> key > new -> key){
        insertValue(root -> left, new);
    } else {
        insertValue(root -> right, new);
    }
}

struct Node *findNode(struct Node *root, int value){
    
    if (root == NULL) return NULL;
    if (root -> key == value) return root;

    if (root -> key < value){
        return findNode(root -> right, value);
    } 
    if (root -> key > value){
        return findNode(root -> left, value);
    }
}

int findLevel(struct Node *root, int level, int value){
    if (root == NULL) return 0;
    if (root -> key == value) {
        printf("\nNode [%d] found on level: [%d]\n", root -> key, level); 
        return level;
    }
    if (root -> key > value){
        return findLevel(root -> left, level + 1, value);
    }
    if (root -> key < value){
        return findLevel(root -> right, level + 1, value);
    }
}

int findNodeLevel(struct Node *root, int level, int value){
    int l = 0;
    if (root == NULL) return 0;
    l = findLevel(root, level, value);
    return l;
}

void insertArrayToTree(struct Node *root, int* values, int size){
    printf("-.-- Adding values to Tree with root [%d] ---- \n", root -> key);
    for (int i = 0; i < size; i++){
        printf("Adding Value: %d\n",values[i]);
        insertValue(root, newNode(values[i]));
        printf("Value added.\n");
    }
    printf("---- End Adding values to Tree ----");
    //printf("%d", root -> left -> key);
    printf("\nNew tree preorder: \n\t-> ");
    printTree(root, "preorder");
    printf("\nNew tree inorder: \n\t-> ");
    printTree(root, "inorder");
    printf("\nNew tree postorder: \n\t-> ");
    printTree(root, "postorder");
    printf("\n");
}