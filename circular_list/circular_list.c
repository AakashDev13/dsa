#include <stdio.h>
#include <stdlib.h>

struct cir_list_node {
    int data;
    struct cir_list_node *next;
    
};

struct cir_list_node *head = NULL;

void insertAtFront(int data) {

    struct cir_list_node *curr = head;
    struct cir_list_node *newNode;
    newNode = (struct cir_list_node *)malloc(sizeof(struct cir_list_node));

    newNode->data = data;
    newNode->next = newNode;

    if(!newNode) {
        printf("Memory Errorr");
        return;
    }

    if(head == NULL) {
        head = newNode;
        head->next = head;
        return;
    }

    while(curr->next != head) {
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->next = head;
    head = newNode;

    return;

}

void insertAtEnd(int data) {
    
    struct cir_list_node *curr = head;
    struct cir_list_node *newNode;
    newNode = (struct cir_list_node *)malloc(sizeof(struct cir_list_node));

    newNode->data = data;
    newNode->next = newNode;

    if(!newNode) {
        printf("Memory Error");
        return;
    }

    if(head == NULL) {
        head = newNode;
        head->next = head;
        return;
    }

    while(curr->next != head) {
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->next = head;

    return;

}

int countNode() {

    struct cir_list_node *curr = head;

    if(head == NULL) {
        printf("List is Empty");
        return -1;
    }

    int count = 0;

    do {
        curr = curr->next;
        count++;
    } while(curr != head);

    return count;


}

void display() {
    struct cir_list_node *curr = head;

    if(head == NULL) {
        printf("List is Empty ");
        return;
    }
    
    do {
        printf("%d ", curr->data);
        curr = curr->next;
    } while(curr != head);

    printf("\n");
}


int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtEnd(60);
    display();
    insertAtFront(5);
    insertAtFront(4);
    insertAtFront(3);
    insertAtFront(2);
    display();
    printf("Total Number of Nodes = %d", countNode());

    return 0;
    
}