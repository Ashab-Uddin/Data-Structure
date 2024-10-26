/**
 * This is the implementation of the circular linked list
 * employing insert-first and delete-first techniques 
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

struct Node* InsertFirst (struct Node* head) {
    struct Node* current = CreateNode ();
    
    //when ll is empty
    if (head == NULL) {
        head = current;
        current->next = head;
        return head;
    }
    
    //if not empty
    struct Node* temp = head;
    //Fine the last node from the LL
    while (temp->next != head) 
        temp = temp->next;
        
    current->next = head;
    temp->next = current;
    head = current;
    
    return head;
}


struct Node* DeleteFirst (struct Node* head) {
    //No node
    if (head == NULL) return NULL;
    
    //1-node in LL
    if (head->next == head) {
        struct Node* current = head;
        head = NULL;
        free (current);
        return head;
    }
    
    //M-node in LL
    struct Node* temp = head;
    while (temp->next != head) 
        temp = temp->next;
    
    struct Node* current = head;
    
    head = current->next;
    temp->next = head;
    free(current);
    
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
    
    head = InsertFirst (head);
    head = InsertFirst (head);
    head = InsertFirst (head);
    
    PrintNodes (head);

    head = DeleteFirst (head);
    PrintNodes (head);
    
    head = DeleteFirst (head);
    PrintNodes (head);
    
    head = DeleteFirst (head);
    PrintNodes (head);
    
    return 0;
}