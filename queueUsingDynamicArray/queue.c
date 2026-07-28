#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int *arr;
    int rear;
    int front;
    int size;
};

// create queue
// isEmpty
// isFull
// enqueue
// dequeue


struct Queue *createQueue(int size) {

    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->arr = (int *)malloc(size * sizeof(int));

    q->size = size;
    q->rear = -1;
    q->front = -1;

    return q;
}


int isEmpty(struct Queue *q) {
    return (q->front == -1);
}

int isFull(struct Queue *q) {
    return (q->rear == q->size - 1);
}


void enqueue(struct Queue *q, int value) {

    if(isFull(q)) {
        printf("Queue is overflow !!");
        return;
    }

    if(isEmpty(q)) {
        q->front = 0;
    }

    q->rear++;
    q->arr[q->rear] = value;

    printf("%d successfully insert into Queue\n", value);

}

int main() {
    struct Queue *Q = createQueue(5);
    // printf("isEmpty %d\n",isEmpty(Q));
    // printf("isFull %d\n",isFull(Q));

    enqueue(Q, 5);
    enqueue(Q, 10);
    enqueue(Q, 15);
    enqueue(Q, 20);
    enqueue(Q, 25);
    return 0;
}