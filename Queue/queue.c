#include <stdio.h>

struct Queue {
    int size;
    int head;
    int tail;
    int capacity;
    int *items;
} * Queue;

struct Queue *newQueue(int size){
    struct Queue *new = malloc(sizeof(struct Queue));
    new -> capacity = 0;
    new -> head = 0;
    new -> tail = size - 1;
    new -> size = size;
    new -> items = (int*)malloc(new->size * sizeof(int));;
    return new;
}

int isFull(struct Queue *q){
    return (q -> capacity == q -> size);
};

int isEmpty(struct Queue *q){
    return (q -> capacity == 0);
}

int getHead(struct Queue *q){
    return q -> items[q -> head];
}

int getTail(struct Queue *q){
    return q -> items[q -> tail];
}

int enqueue(struct Queue *q, int key){
    if (isFull(q)) return 0;
    q -> tail = (q -> tail + 1) % q -> size;
    q -> items[q -> tail] = key;
    q -> capacity = q -> capacity + 1;
    printf("---\nEnqueued value: %d\nQueue capacity: %d\n---\n\n", key, q->capacity);
}

int dequeue(struct Queue *q){
    if (isEmpty(q)) return 0;
    int item = q -> items[q -> head];
    q -> head = (q -> head + 1) % q -> size;
    q -> capacity = q -> capacity - 1;
    printf("Dequeued value: %d\nQueue size: %d\nQueue capacity: %d\n", item, q->size,q->capacity);
    return item;
}