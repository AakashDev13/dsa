#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int *arr;
    int top;
    int size;
};

void *push(struct Stack s, int value) {

    if(s->top == size-1) {
        printf("Stack overflow!!");
        return NULL;
    }
}

struct Stack *createStack(int size) {

    // Allocation memory for stack
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

    if(stack == NULL) {
        printf("Error in Memory Allocation!");
        return NULL;
    }

    // Allocate memorry for the array
    stack->arr = (int *)malloc(size * sizeof(int));

    if(stack->arr == NULL) {
        printf("memory Allocation failed!");
        free(stack);
        return NULL;
    }

    stack->size = size;
    stack->top = -1;

    return stack;
}

int main() {
    
    int size;
    printf("Enter size of Stack! ");
    scanf("%d", &size);

    struct Stack *s = createStack(size);

    if(s == NULL) {
        return 1;
    }

    printf("Stack is created successfully\n");
    printf("Size : %d\n",s->size);
    printf("Top : %d\n", s->top);

    free(s->arr);
    free(s);


}