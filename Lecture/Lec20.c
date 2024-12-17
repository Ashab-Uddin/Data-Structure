#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

int front = -1;
int rear = -1;

bool isEmpty () {
    if (front == -1) return true;
    else return false;
}

bool isFullAtFront () {
    if (front == 0) return true;
    else return false;
}

bool isFullAtRear () {
    if (rear == SIZE - 1) return true;
    else return false;
}

void enQueueFront (int Q[], int element) {
    if (isFullAtFront()) {
        printf ("Full at front\n");
        return;
    }
    else if (isEmpty()) 
        front = rear = 0;
    else
        front -= 1;
    Q[front] = element;
}


void enQueueRear (int Q[], int element) {
    if (isFullAtRear()) {
        printf ("Full at rear\n");
        return;
    }
    else if (isEmpty()) 
        front = rear = 0;
    else
        rear += 1;
    Q[rear] = element;
}

int getFront (int Q[]) {
    return Q[front];
}

int getRear (int Q[]) {
    return Q[rear];
}

void deQueueFront (int Q[]) {
    if (isEmpty()) {
        printf ("Queue is Empty\n");
        return;
    }
    else if (front > rear) {
        front = rear = -1;
        return;
    }
    else 
        front += 1;
}

void deQueueRear (int Q[]) {
    if (isEmpty()) {
        printf ("Queue is Empty\n");
        return;
    }
    else if (front > rear) {
        front = rear = -1;
        return;
    }
    else 
        rear -= 1;
}

void Display (int Q[]) {
    if (isEmpty()) {
        printf ("Queue is Empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
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
    deQueueRear (Queue);
    Display (Queue);
    deQueueFront (Queue);
    Display (Queue);
    return 0;
}