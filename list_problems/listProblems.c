#include<stdio.h>
#include<stdlib.h>
#include "list.h"


/* 
------Problems-------
1.Insert/Delete -> done
2.Reverse LL -> done
3.Middle Node
4.Detect Loop
5.Merge Two Sorted Lists
6.Palindrome
7.K-Reverse
8.Intersection
9.Random Pointer Copy
10.LRU Cache

*/

// 5. Merge Two sorted lists

struct ListNode *mergeList(struct ListNode *head, struct ListNode *head1) {
    
    if(head == NULL) return head1;
    if(head1 == NULL) return head;

    struct ListNode *newHead = NULL;
    struct ListNode *temp = NULL;

    // select first node

    if(head->data <= head1->data)  {
        newHead = head;
        head = head->next;
    } else {
        newHead = head1;
        head1 = head1->next;
    }

    temp = newHead;


    // Merge 
    while(head && head1) {
        
        if(head->data <= head1->data) {
            temp->next = head;
            head = head->next;
        } else {
            temp->next = head1;
            head1 = head1->next;
        }

        temp = temp->next;
    }

    // Attach Remaining Nodes

    if(head) {
        temp->next = head;
    } else {
        temp->next = head1;
    }

    return newHead;
}

// 4. Detect Loop Using slow and fast pointer

int isLoop2(struct ListNode *head) {

    struct ListNode *slow ,*fast;
    slow = fast = head;
    
    do{
        slow = slow->next;
        fast = fast->next;
        fast = fast ? fast->next : fast;


    }while(fast && slow && fast != slow);

    if(slow == fast) {return 1;}
    else return 0;
}

int isLoop(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {return 1;}
    }     
    return 0;
}

// 2. middle node of linked list 

// using toggle boolean method
struct ListNode *middleNodeToggle(struct ListNode *head) {
    struct ListNode *temp = head;
    struct ListNode *mid = head;
    
    int count = 0;

    while(temp != NULL) {
        if(count % 2 == 1) {
            mid = mid->next;
        }
        count++;
        temp = temp->next;
    }
    return mid;
}

// slow and fast pointer method

struct ListNode *middleNode(struct ListNode *head) {

    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while(fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}




// reverse using look and 3 pointer
void reverseList(struct ListNode **head) {
    struct ListNode *p = *head;
    struct ListNode *q = NULL, *r = NULL;

    while(p != NULL) {
        r = q;
        q = p;
        p = p->next;

        q->next = r;
    }
    *head = q;

    printf("List is Reversed!\n");

}

// reverse using recursion 

void reverseListR(struct ListNode *q , struct ListNode *p , struct ListNode **head) {

    if(p != NULL) {
        reverseListR(p, p->next, head);
        p->next = q;
    } else {
        *head = q;
    }
}

int main() {


    int arr[] = {1, 4, 6, 9, 10, 32, 45, 67};
    int arr1[] = {2, 5, 12, 14, 15};
    int size = sizeof(arr)/ sizeof(arr[0]);

    struct ListNode *head = createUsingArr(arr, size);
    displayList(head);

    struct ListNode *head1 = createUsingArr(arr1, size);
    displayList(head1);


    printf("List after merge!\n");
    struct ListNode *marge = mergeList(head, head1);
    displayList(marge);


    // create loop
    /*
    struct ListNode *t1 = head->next;
    struct ListNode *t2 = head->next->next->next->next;
    t2->next = t1;
    
    if(isLoop(head)) {
        printf("LOOP EXIST!!");
        return 0;
    }else {
        printf("LOOP NOT EXIST!\n");
        displayList(head);
    }
    displayList(head);
    */
    
    // struct ListNode *mid = middleNode(head);
    // printf("Middle Node of List is = %d \n", mid->data);
    
    // struct ListNode *List1 = NULL;
    // struct ListNode *List2 = NULL;

    // insertAtEnd(&List1, 10);
    // insertAtEnd(&List1, 20);
    // insertAtEnd(&List1, 30);
    // insertAtEnd(&List1, 40);
    // insertAtEnd(&List1, 50);
    // insertAtEnd(&List2, 1);
    // insertAtEnd(&List2, 2);
    // insertAtEnd(&List2, 3);
    // insertAtEnd(&List2, 4);
    // insertAtEnd(&List2, 5);
    // insertAtEnd(&List2, 6);

    // displayList(List1);
    // displayList(List2);
    // struct ListNode *mid = middleNode(List2);
    // printf("Middle Element of List = %d\n", mid->data);

    // displayList(List2);
    // reverseListR(NULL, List1, &List1);
    // displayList(List1);

    // reverseList(&List1);
    // reverseList(&List2);
    // displayList(List1);
    // displayList(List2);

    return 0;
}