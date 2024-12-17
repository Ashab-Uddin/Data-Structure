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

void enQueue (int Q[], int element) {
    if (isFull()) {
        printf ("Queue is full\n");
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

void deQueue (int Q[]) {
    if (isEmpty()) {
        printf ("Queue is empty\n");
        return;
    }
    else if (front > rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void Display (int Q[]) {
    if (isEmpty()) {
        printf ("Queue is empty\n");
        return;
    }
    
    for (int i = front; i <= rear; i = (i + 1) % SIZE)
        printf ("%d ", Q[i]);
    printf ("\n");
}

int main () {
    int Queue[SIZE];
    enQueue (Queue, 45);
    enQueue (Queue, 58);
    enQueue (Queue, 93);
    Display (Queue);
    deQueue (Queue);
    Display (Queue);
    deQueue (Queue);
    Display (Queue);
    deQueue (Queue);
    Display (Queue);
    deQueue (Queue);
    Display (Queue);
    enQueue (Queue, 93);
    Display (Queue);
    
    return 0;
}