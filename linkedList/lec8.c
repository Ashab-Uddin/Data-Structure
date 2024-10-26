#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct Node* head = NULL;

int main () {
    struct Node it;
    if (head == NULL) head = &it;
    
    it.value = 20;
    it.next = NULL;
    
    struct Node it1;
    it1.value = 30;
    it1.next = NULL;
    
    it.next = &it1;

    struct Node it2;
    it2.value = 60;
    it2.next = NULL;

    it1.next = &it2; 
    
    struct Node *temp = head;
    while (temp != NULL) {
        printf ("%d\n", temp->value);
        temp = temp->next;
    }
    
    return 0;
}



