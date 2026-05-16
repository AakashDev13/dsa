#include <stdio.h>
#include <stdlib.h>

struct cir_list_node {
    int data;
    struct cir_list_node *next;
    
};

struct cir_list_node *head = NULL;

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
}


int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtEnd(60);
    display();
}