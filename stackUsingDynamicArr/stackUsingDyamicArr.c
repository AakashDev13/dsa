#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int *arr;
    int top;
    int size;
};

typedef struct Stack;

struct *createStack(int size) {

    // Allocation memory for stack
    Stack *stack = (Stack *)malloc(sizeof(Stack));

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
    scanf("%d", size);
    Stack *s = createStack(size);


}