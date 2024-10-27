#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to merge two lists without sorting
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;  // Link end of first list to start of second list

    return head1;  // Return head of the merged list
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // Creating first linked list
    appendNode(&head1, 56);
    appendNode(&head1, 78);
    appendNode(&head1, 96);

    // Creating second linked list
    appendNode(&head2, 48);
    appendNode(&head2, 64);
    appendNode(&head2, 84);

    printf("First Linked List:\n");
    printList(head1);

    printf("Second Linked List:\n");
    printList(head2);

    // Merging lists without sorting
    struct Node* mergedHead = mergeLists(head1, head2);

    printf("Merged Linked List (Not Sorted):\n");
    printList(mergedHead);

    return 0;
}
