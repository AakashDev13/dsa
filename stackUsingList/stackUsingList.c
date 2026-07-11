#include<stdio.h>
#include<stdlib.h>

// Stack Using Linked list

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// push operation 
void push(int value) {

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if(newNode == NULL) {
        printf("Error in Memory Allocation!!");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d Element pushed succussefully!\n", value);

}
// pop operation 

void pop() {
    if(top == NULL) {
        printf("Stack is underflow");
        return;
    }
    struct Node *temp = top;
    top = top->next;
    printf("%d Element is poped\n", temp->data);
    free(temp);
}

// peek operation 

void peek() {

    if(top == NULL) {
        printf("Stack is Empty");
        return;
    }
    else {
        printf("\nTop Element : %d\n", top->data);
        return;
    }
}

// display stack 
void display() {

    
    struct Node *temp = top;

    if(temp == NULL) {
        printf("stack underflow!!");
        return;
    }

    printf("Display Stack Elements : \n");
    while(temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }

}



int main() {

    push(10);
    push(20);
    pop();
    push(30);
    pop();
    push(40);
    push(50);
    push(60);
    pop();

    peek();
    display();
}