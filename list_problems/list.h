#include<stdio.h>
#include<stdlib.h>

// create a header file
#ifndef LIST_H
#define LIST_H

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *head = NULL;

void insertAtBegnning(int data) {

    struct ListNode *temp;
    temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->data = data;
    temp->next = NULL;

    if(temp == NULL) {
        head = temp;
        head->next = NULL;
        return;
    }

    temp->next = head;
    head = temp;

}

void insertAtEnd(int data) {
    struct ListNode *temp , *curr = head;
    temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->data = data;
    temp->next = NULL;

    if(curr == NULL) {
        head = temp;
        head->next == NULL;
        return;
    }

    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
}

int sizeoflist() {
    struct ListNode *curr = head;
    int count = 0;
    while(curr != NULL) {
        curr = curr->next;
        count++;
    }
    return count;
}

void insertAtGivenPos(int data, int pos) {
    
    struct ListNode *temp;
    temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->data = data;
    temp->next = NULL;


    if(head == NULL ) {
        head = temp;
        head->next = NULL;
        return;
    }

    int i = 0;
    struct ListNode *curr = head, *prev = NULL;

    if(pos == 0) {
        temp->next = head;
        head = temp;
        return;
    }

    while(i < pos && curr != NULL) {
        prev = curr;
        curr = curr->next;
        i++;
    }

    if(curr == NULL || pos < 0) {
        printf("\nInvalid index Try Between %d and %d \n", 0 , sizeoflist());
        return;
    }

    temp->next = curr;
    prev->next = temp;

}

void deleteAtBignning() {

    if(head == NULL) {
        printf("List is Empty");
        return;
    }
    struct ListNode *temp = head;
    head = head->next;
    free(temp);
    return;
}

// Deleting node from End of list
void deleteAtEnd() {

}

// Deleting node at end
void deleteAtGivenPos(int pos) {
    if(head == NULL) {
        printf("List is Empty");
    }
    struct ListNode *prev = NULL, *curr = head;
    int i = 0;
    while(i < pos && curr != NULL) {
        prev = curr;
        curr = curr->next;
        i++;
    }
    if(curr == NULL) {
        printf("\nInvalid Position\n");
        return;
    }
    prev->next = curr->next;
    curr->next = NULL;
    free(curr);
    return;
}


void displayList() {

    struct ListNode *temp = head;

    if(temp == NULL) {printf("\nList Underflow!!!!!!");}
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

#endif