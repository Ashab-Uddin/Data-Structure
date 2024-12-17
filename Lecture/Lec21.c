#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

int front = -1;
int rear = -1;

bool isEmpty () {
    if (front == -1) return true;
    else return false;
}

bool isFull () {
    if (front == (rear + 1) % SIZE) return true;
    else return false;
}

void enQueueFront (int Q[], int element) {
    if (isFull()) {
        printf ("Queue is Full\n");
        return;
    }
    else if (isEmpty()) 
        front = rear = 0;
    else
        front = (front - 1 + SIZE) % SIZE;
    Q[front] = element;
}

void enQueueRear (int Q[], int element) {
    if (isFull()) {
        printf ("Queue is Full\n");
        return;
    }
    else if (isEmpty()) 
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;
    Q[rear] = element;
}

int getFront (int Q[]) {
    return Q[front];
}

void deQueueFront (int Q[]) {
    if (isEmpty()) {
        printf ("Queue is Empty\n");
        return;
    }
    else if (front == rear) {
        front = rear = -1;
        return;
    }
    else 
        front = (front + 1) % SIZE;
}

void deQueueRear (int Q[]) {
    if (isEmpty()) {
        printf ("Queue is Empty\n");
        return;
    }
    else if (front == rear) {
        front = rear = -1;
        return;
    }
    else 
        rear = (rear - 1 + SIZE) % SIZE;
}


void Display (int Q[]) {
    if (isEmpty()) {
        printf ("Queue is Empty\n");
        return;
    }
    for (int i = front; i != (rear + 1) % SIZE; i = (i + 1) % SIZE)
        printf ("%d ", Q[i]);
    printf ("\n");
}

int main () {
    int Queue[SIZE];
    enQueueFront (Queue, 45);
    enQueueRear (Queue, 54);
    enQueueFront (Queue, 98);
    Display (Queue);
    deQueueFront (Queue);
    Display (Queue);
    deQueueRear (Queue);
    Display (Queue);
    deQueueFront (Queue);
    Display (Queue);
    deQueueRear (Queue);
    Display (Queue);
    return 0;
}