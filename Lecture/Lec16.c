/**
 * Stack implementation employing LL
 */

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

struct Node* Push (struct Node* head) {
    struct Node* current = CreateNode ();
    
    if (head == NULL) {
        head = current;
        return head;
    }
    
    //Identifying the last node in LL
    struct Node* temp = head;
    while (temp->next != NULL) 
        temp = temp->next;
    
    temp->next = current;
    
    return head;
}


struct Node* Pop (struct Node* head) {
    //No node in LL
    if (head == NULL) {
        printf ("Underflow\n");
        return NULL;
    }
    else if (head->next == NULL) {
        struct Node* current = head;
        head = NULL;
        free (current);
        return head;
    }
    else {
        struct Node* temp = head;
        while (temp -> next -> next != NULL) 
            temp = temp->next;
        
        struct Node* current = temp->next;
        temp->next = NULL;
        free (current);
    }
    
    return head;
}


void PrintNodes (struct Node* head) {
    if (head == NULL) return;
    
    struct Node* temp = head;
    while (temp != NULL) {
        printf ("%d ", temp->value);
        temp = temp->next;
    }
    printf ("\n");
}


int main () {
    struct Node* head = NULL;
    
    head = Push (head);
    head = Push (head);
    head = Push (head);
    
    PrintNodes (head);
    
    head = Pop (head);
    PrintNodes (head);
    head = Pop (head);
    PrintNodes (head);
    head = Pop (head);
    PrintNodes (head);
    
    return 0;
}