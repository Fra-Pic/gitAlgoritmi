
typedef struct Array{
    int *items;
    int size;
    int index;
};

struct Array *newArray(int *values, int size){
    struct Array *new = malloc(sizeof(struct Array));
    new -> index = 0;
    new -> items = values;
    new -> size = size;
    return new;
}

int getIndex(struct Array *arr){
    return arr -> index;
}

int printArrayValues(struct Array *arr){
    if (arr -> size == 0) {
        printf("Empty array, index: %d\n", arr -> index);
    } else {
        for (int i = 0; i < arr -> size; i++){
            printf("arr val: %d\n", arr -> items[i]);
        }
    }
}

int push(struct Array *arr, int val){
    //printf("pushed %d at %d inside array\n", val, getIndex(arr));
    printf("pushing: %d at index: %d\n", val, arr -> index);
    int i = arr -> index;
    arr -> items[i] = val;
    arr -> index = arr -> index + 1;
    arr -> size = arr -> size + 1;
    
    //printArrayValues(arr);
    printf("pushed: %d\n", val);
    printf("---------------\n");
}

int pop(struct Array *arr){
    int elem = arr -> items[arr -> size - 1];
    arr -> index = arr -> index - 1;
    arr -> size = arr -> size - 1;
    return elem;
}