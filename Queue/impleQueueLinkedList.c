#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (front == NULL && rear == NULL) { // Check if queue is empty
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("\nEnqueue Data Successfully\n");
}

void dequeue() {
    struct node *temp;
    if (front == NULL && rear == NULL) { // Check if queue is empty
        printf("The Queue is Empty\n");
    } else {
        temp = front;
        front = front->next;
        free(temp);

        if (front == NULL) { // If the queue becomes empty
            rear = NULL;
        }
        printf("\nDequeued Successfully\n");
    }
}

void Display() {
    struct node *temp = front;

    if (front == NULL) { // Check if queue is empty
        printf("The Queue is Empty\n");
    } else {
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nQueue Implementation Using Linked List\n");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n0. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                Display();
                break;
            case 0:
                printf("Exiting....\n");
                break;
            default:
                printf("Invalid Choice! Please Try Again\n");
        }
    } while (choice != 0);

    return 0;
}
