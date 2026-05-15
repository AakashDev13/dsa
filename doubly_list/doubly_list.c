#include <stdio.h>
#include <stdlib.h>

struct doubly_list_node
{
    struct doubly_list_node *next;
    int data;
    struct doubly_list_node *prev;
  
};

struct doubly_list_node *head = NULL;
struct doubly_list_node *tail = NULL;



void insertAtBegnning(int data) {
    
    struct doubly_list_node *newNode;
    newNode = (struct doubly_list_node *)malloc(sizeof(struct doubly_list_node));
    
    
    if(newNode == NULL) {
        printf("Memory Error");
        return;
    }
    
    newNode->next = NULL;
    newNode->data = data;
    newNode->prev = NULL;

    if(head == NULL) {
        tail = head = newNode;
        return;
    }
    
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    return;
}

void insertAtEnd(int data) {

    struct doubly_list_node *newNode = tail;
    newNode = (struct doubly_list_node*)malloc(sizeof(struct doubly_list_node));

    newNode->next = NULL;
    newNode->data = data;
    newNode->prev = NULL;

    if(newNode == NULL) {
        printf("Memory Error!\n");
        return;
    }

    if(tail == NULL) {
        tail = head = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = NULL;
    tail = newNode;
    return;

}

void insertAtGivenPos(int data, int pos) {

    struct doubly_list_node *curr = head;
    struct doubly_list_node *newNode;
    
    newNode = (struct doubly_list_node*)malloc(sizeof(struct doubly_list_node));

    if(newNode == NULL) {printf("Memory Error !"); return;}

    newNode->next = NULL;
    newNode->data = data;
    newNode->prev = NULL;

    // Empty list
    if(head == NULL) {
        head = tail = newNode;
        return;
    }

    // Insert at pos == 0
    
    if(pos == 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    int k = 0;

    while(k < pos-1 && curr != NULL) {
        curr = curr->next;
        k++;
    }

    // Invalid position

    if(curr == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    // Insert At End 

    if(curr->next == NULL) {
        curr->next = newNode;
        newNode->prev = curr;
        tail = newNode;
        return;
    }

    // Insert at given position

    newNode->next = curr->next;
    curr->next->prev = newNode;

    curr->next = newNode;
    newNode->prev = curr;

    return;
   
}

// Deleting Node in doubly list 

// delete front node 

void deleteAtFront() {

    if(head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct doubly_list_node *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    return;
}


// delete end node

void deleteAtEnd() {

    if(tail == NULL) {
        printf("\nList is Empty\n");
        return;
    }

    struct doubly_list_node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(temp);

    return;
}

void deleteAtGivenPos(int pos) {

    struct doubly_list_node *curr = head;

    if(curr == NULL) {
        printf("\nList is empty\n");
        return;
    }

    // delete At first position  , pos = 0

    if(pos == 0) {
        head = head->next;
        head->prev = NULL;
        free(curr);
        return;
    }


    int k = 0;

    while(k < pos - 1 && curr != NULL) {
        curr = curr->next;
        k++;
    }

    // Delete At last position , pos = tail

    if(curr == NULL) {
        tail = tail->prev;
        tail->next = NULL;
        free(curr);
        return;
    }

    curr->next->next = curr->next;
    curr->next->next->prev = curr;
    free(curr->next);

    return;
}

void display_list() {
    struct doubly_list_node *temp = head;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

}

int main() {
    display_list();
    insertAtBegnning(5);
    insertAtBegnning(4);
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtBegnning(3);
    insertAtGivenPos(12, 3);
    display_list();
    deleteAtGivenPos(3);
    // deleteAtFront();
    // display_list();
    // deleteAtEnd();
    display_list();

}