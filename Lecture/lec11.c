#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct Node* CreateNode () {
    struct Node* current = (struct Node*) malloc (sizeof (struct Node));
    printf ("Put a value: ");
    scanf ("%d", &(current->value));
    current->next = NULL;
    return current;
}

struct Node* InsertAny (struct Node* head, int position) {
    struct Node* current = CreateNode ();
    
    if (position == 0) {
        current->next = head;
        head = current;
        return head;
    }
    
    struct Node* temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;
    
    if (temp == NULL) {
        printf ("Out of bound\n");
        return head;
    }
    
    current->next = temp->next;
    temp->next = current;
    
    return head;
}


void PrintNodes (struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf ("%d ", temp->value);
        temp = temp->next;
    }
    printf ("\n");
}

/*
struct Node* DeleteLast (struct Node* head) {
    if (head == NULL) return NULL;
    else if (head->next == NULL) {
        struct Node* current = head;
        head = NULL;
        free (current);
    }
    else {
        struct Node* temp = head;
        while (temp->next->next != NULL) 
            temp = temp->next;
        
        struct Node* current = temp->next;
        temp->next = NULL;
        free (current);
    }
    
    return head;
}
*/

int main () {
    struct Node* head = NULL;
    
    head = InsertAny (head, 0);
    head = InsertAny (head, 1);
    head = InsertAny (head, 1);

    PrintNodes (head);
    
    
    return 0;
}