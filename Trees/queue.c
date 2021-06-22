#include <stdio.h>
#include <stdlib.h>

#define GREEN   "\x1b[32m"
#define RED     "\x1b[35m"
#define WHITE   "\x1b[0m"

typedef struct Queue{
    int *values;
    int size;
    int capacity;
    int head;
    int tail;
};

struct Queue *newQueue(int size){
    struct Queue *q = malloc(sizeof(struct Queue));
    q -> values = (int*)malloc(size * sizeof(int));
    q -> size = size;
    q -> head = 0;
    q -> tail = -1;
    q -> capacity = 0;
}

int isEmpty(struct Queue *q){
    return (q -> capacity == 0);
}

int isFull(struct Queue *q){
    return (q -> size == q -> capacity);
}

int enqueue(struct Queue *q, int val){
    if (isFull(q) || q -> tail > q -> size){
        printf(RED "Queue full.\n" WHITE);
        return 0;
    } else {
        q -> tail = q -> tail + 1;
        q -> values[q -> tail] = val;
        q -> capacity = q -> capacity + 1;
        printf(GREEN "| ENQUEUE |\tElement [%d] in position [%d], head is [%d]\t|\tQueue occupied spaces [%d/%d]\n" WHITE, val, q -> tail, q -> head, q ->capacity, q ->size);
        return 1;
    }
}

int dequeue(struct Queue *q){
    if (isEmpty(q) || q ->head > q ->size){
        printf("Empty queue.\n");
        return 0;
    } else {
        int elem = q -> values[q -> head];
        q -> head = q -> head + 1;
        q -> capacity = q -> capacity - 1;
        printf(RED "| DEQUEUE |\tElement [%d] in position [%d], tail is [%d]\n" WHITE, elem, q -> head, q -> tail);
        return elem;
    }
}

void insertArrayToQueue(struct Queue *q, int *values, int size){
    printf("\n--- Inserting values into Queue--- \n");
    for (int i = 0; i < size; i++){
        enqueue(q, values[i]);
    }
    printf("---- End Inserting values to Queue ----\n");
}

void dequeueArray(struct Queue *q){
    printf("\n--- Dequeuing values into Queue--- \n");
    for (int i = 0; i < q -> size; i++){
        dequeue(q);
    }
    printf("---- End Dequeue values to Queue ----\n");
}

void printQueue(struct Queue *q){
    int i = q -> head;
    printf("\n---- Printing Queue ----\n");
    for (i; i >= 0; i++){
        printf("%d ", q ->values[i]);
    }
    printf("\n---- Printing Queue End ----\n");
}