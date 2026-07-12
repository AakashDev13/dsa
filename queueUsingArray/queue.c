// queue using Array (FIFO)

#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

int queue[SIZE];
int front = -1;
int rear = -1;

// enqueue
// dequeue
// peek 

void peek() {
    
    printf("Peek Element : ");
    if(rear == front && rear == -1) {
        printf("Queue is Empty");
        return;
    }
    printf("%d \n", queue[front + 1]);
    return;
}

void enqueue(int value) {
    
    if(rear > 0 && rear == front) {
        printf("Queue is Full");
        return;
    }

    rear++;
    queue[rear] = value;
}

void dequeue() {
    if(rear == -1) {
        printf("Queue is Empty");
        return;
    }
    front++;
}

void display() {

    if(rear == -1 || rear == front) {
        printf("Queue is Empty");
        return;
    }

    for(int i = front + 1; i <= rear; i++ ){
        printf("%d ", queue[i]);
    }
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    dequeue();
    peek();
    display();


    return 0;
}