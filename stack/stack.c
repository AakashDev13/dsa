#include<stdio.h>
#include<stdlib.h>

/*--- Stack Using Array */

// push 
// pop
// isEmpty
// isFull

#define SIZE 5
int top = -1;

int isFull() {
    if(top == SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty() {
    if(top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void push(int st[], int el) {

    // if(top == SIZE - 1){
    //     printf("Stack Overflow!!!!!");
    //     return;
    // }
    if(isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    st[++top] = el;
    printf("Pushed %d Successfully!\n", el);
}

int pop(int st[]) {
    int x = -1;
    if(top == -1) {
        printf("Stack is Empty, can't be poped Element!\n");
        return x;
    }
    x = st[top--];

    return x;
}



void display(int st[], int size) {

    if(top == -1 ) {
        printf("Stack is Empty!\n");
        return;
    }
    for(int i = 0; i <= top ; i++) {
        printf("%d ", st[i]);
    }
}


int main() {

    int st[SIZE];

    push(st, 1);
    push(st, 2);
    push(st, 3);
    
    push(st, 4);
    push(st, 5);
    push(st, 55);

    display(st, SIZE);
    
    return 0;
}

