#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;
struct Node* tail = NULL;

struct Node* CreateNode () {
    struct Node* current = (struct Node*) malloc (sizeof (struct Node));
    printf ("Put a value: ");
    scanf ("%d", &(current->value));
    current->next = NULL;
    current->prev = NULL;
    return current;
}

struct Node* InsertFirst () {
    struct Node* current = CreateNode ();
    
    if (head == NULL) {
        head = current;
        tail = current;
        return head;
    }
    
    current->next = head;
    head->prev = current;
    head = current;
    
    return head;
}

struct Node* InsertLast () {
    struct Node* current = CreateNode ();
    
    if (head == NULL) {
        head = current;
        tail = current;
        return head;
    }
    
    current->prev = tail;
    tail->next = current;
    tail = current;
    return head;
}

struct Node* DeleteFirst () {
    if (head == NULL) return NULL;
    
    if (head == tail) {
        struct Node* current = head;
        head = NULL;
        tail = NULL;
        free (current);
        return head;
    }
    
    struct Node* current = head;
    head = head -> next;
    head -> prev = NULL;
    free (current);
    return head;
}

struct Node* DeleteLast () {
    if (head == NULL) return NULL;
    else if (head->next == NULL) {
        struct Node* current = head;
        head = NULL;
        tail = NULL;
        free (current);
    }
    else {
        struct Node* current = tail;
        tail->prev->next = NULL;
        tail = tail->prev;
        free (current);
    }
    
    return head;
}


void PrintForward () {
    struct Node* temp = head;
    while (temp != NULL) {
        printf ("%d ", temp->value);
        temp = temp->next;
    }
    printf ("\n");
}

void PrintBackward () {
    struct Node* temp = tail;
    while (temp != NULL) {
        printf ("%d ", temp->value);
        temp = temp->prev;
    }
    printf ("\n");
}



int main () {    
    head = InsertLast ();
    head = InsertLast ();
    head = InsertFirst ();
 
    PrintForward();
    PrintBackward ();

    head = DeleteLast();
    PrintForward();
    PrintBackward ();
    
    head = DeleteFirst();
    PrintForward();
    PrintBackward ();
    
    head = DeleteLast();
    PrintForward();
    PrintBackward ();
    
    return 0;
}