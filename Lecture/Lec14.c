/**
 * This is the implementation of the circular linked list
 * employing insert-last and delete-last techniques 
 * */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct Node* CreateNode () {
    struct Node* current = (struct Node*) malloc (sizeof(struct Node*));
    printf ("Put a value: ");
    scanf ("%d", &(current->value));
    current->next = NULL;
    return current;
}

struct Node* InsertLast (struct Node* head) {
    struct Node* current = CreateNode ();
    
    //no node in LL
    if (head == NULL) {
        head = current;
        current->next = head;
        return head;
    }
    
    //M-node in LL
    struct Node* temp = head;
    while (temp->next != head) 
        temp = temp->next;
    
    current->next = head;
    temp->next = current;
    
    return head;
}

struct Node* DeleteLast (struct Node* head) {
    //No node in LL
    if (head == NULL) return NULL;
    //1-node in LL
    else if (head->next == head) {
        struct Node* current = head;
        head = NULL;
        free (current);
        return head;
    }
    //M-node in LL
    else {
        struct Node* temp = head;
        while (temp -> next -> next != head) 
            temp = temp->next;
        
        struct Node* current = temp->next;
        temp->next = head;
        free (current);
    }
    
    return head;
}

void PrintNodes (struct Node* head) {
    if (head == NULL) return;
    
    struct Node* temp = head;
    do {
        printf ("%d ", temp->value);
        temp = temp->next;
    } while (temp != head);
    printf ("\n");
}


int main () {
    struct Node* head = NULL;
    
    head = InsertLast (head);
    head = InsertLast (head);
    head = InsertLast (head);
    
    PrintNodes (head);
    
    head = DeleteLast (head);
    PrintNodes (head);
    head = DeleteLast (head);
    PrintNodes (head);
    head = DeleteLast (head);
    PrintNodes (head);
    
    return 0;
}