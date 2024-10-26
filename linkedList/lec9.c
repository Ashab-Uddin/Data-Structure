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
    
    if (head == NULL) {
        head = current;
        return head;
    }
    
    current->next = head;
    head = current;
    
    return head;
}
/*

struct Node* DeleteFirst (struct Node* head) {
    struct Node* current = head;
    
    head = head->next;
    free(current);
    
    return head;
}

*/

void PrintNodes (struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf ("%d ", temp->value);
        temp = temp->next;
    }
    printf ("\n");
}


int main () {
    struct Node* head = NULL;
    
    head = InsertFirst (head);
    head = InsertFirst (head);
    head = InsertFirst (head);
    
    PrintNodes (head);
    /*
    head = DeleteFirst (head);
    PrintNodes (head);
    */
    
    return 0;
}