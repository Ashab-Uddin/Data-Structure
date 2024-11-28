#include <stdio.h>
#define N 5

int Queue[N];
int front = -1;
int rear = -1;

// Function to add an element to the queue
void enqueue() {
    int x;
    if (rear == N - 1) {
        printf("The Queue is Full\n");
    } else {
        printf("Enter the value to enqueue: ");
        scanf("%d", &x);
        if (front == -1 && rear == -1) {
            front = rear = 0;
        } else {
            rear++;
        }
        Queue[rear] = x;
        printf("%d added to the queue\n", x);
    }
}

// Function to remove an element from the queue
void dequeue() {
    if (front == -1 && rear == -1) {
        printf("The Queue is Empty\n");
    } 
    else if(front == rear) {
        printf("%d dequeued from the queue\n", Queue[front]);
        front = rear = -1;
    }
    else{
        printf("%d dequeued from the queue\n",Queue[front]);
        front++;
    }
    
    }


// Function to display the elements in the queue
void display() {
    if (front == -1 || front > rear) {
        printf("The Queue is Empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", Queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nWelcome to the Queue Data Structure\n");
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display List\n");
        printf("0. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
