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
    
    struct Node *temp = head;
    while (temp != NULL) {
        printf ("%d\n", temp->value);
        temp = temp->next;
    }
    
    return 0;
}



/*
struct Item {
    int a;
    struct Item *b;
}; 


int main () {
    struct Item it, it1;
    it.a = 24;
    it.b = &it1;
    
    printf ("%d \n", it.a);
    
    (it.b)->a = 45;
    
    printf ("%d %d\n", it1.a, (it.b)->a);
    
    return 0;
}
*/
