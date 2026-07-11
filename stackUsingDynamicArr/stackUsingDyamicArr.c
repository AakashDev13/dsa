#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int *arr;
    int top;
    int size;
};

int isEmpty(struct Stack *s) {
    if(s->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(struct Stack *s) {
    if(s->top == s->size - 1) {
        return 1;
    }else {
        return 0;
    }
}
void display(struct Stack *s) {
    
    if(s->top == -1) {
        printf("Stack is underflow!!");
        return;
    }
    for(int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
}

void pop(struct Stack *s) {


    if(s->top == -1) {
        printf("Stack is underFlow");
        return;
    }
    s->top--;
} 

void push(struct Stack *s, int value) {

    if(s->top == s->size - 1) {
        printf("Stack overflow!!");
        return;
    }
    s->top++;
    s->arr[s->top] = value;
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
    printf("%d\n", isEmpty(s));
    printf("%d\n", isFull(s));
    push(s, 8);
    push(s, 12);
    push(s, 16);
    pop(s);
    pop(s);
    push(s, 20);
    push(s, 34);
    printf("Size : %d\n",s->size);
    printf("Top : %d\n", s->top);

    display(s);

    free(s->arr);
    free(s);


}