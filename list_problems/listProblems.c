#include<stdio.h>
#include<stdlib.h>
#include "list.h"

void reverseList() {

}

int main() {

    struct ListNode *List1 = NULL;

    insertAtEnd(&List1, 10);
    insertAtEnd(&List1, 20);
    insertAtEnd(&List1, 30);
    insertAtEnd(&List1, 40);
    insertAtEnd(&List1, 50);
    displayList(List1);

    return 0;
}