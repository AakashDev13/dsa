#include<stdio.h>
#include<stdlib.h>
#include "list.h"


/* 
------Problems-------
1.Insert/Delete -> done
2.Reverse LL -> done
3.Middle Node
4.Detect Loop
5.Merge Lists
6.Palindrome
7.K-Reverse
8.Intersection
9.Random Pointer Copy
10.LRU Cache

*/


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

    struct ListNode *List1 = NULL;
    struct ListNode *List2 = NULL;

    insertAtEnd(&List1, 10);
    insertAtEnd(&List1, 20);
    insertAtEnd(&List1, 30);
    insertAtEnd(&List1, 40);
    insertAtEnd(&List1, 50);
    insertAtEnd(&List2, 1);
    insertAtEnd(&List2, 2);
    insertAtEnd(&List2, 3);
    insertAtEnd(&List2, 4);
    insertAtEnd(&List2, 5);
    insertAtEnd(&List2, 6);

    displayList(List1);
    // displayList(List2);
    reverseListR(NULL, List1, &List1);
    displayList(List1);

    // reverseList(&List1);
    // reverseList(&List2);
    // displayList(List1);
    // displayList(List2);

    return 0;
}