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
    if (rear == SIZE - 1) return true;
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
        rear += 1;
    
    Q[rear] = element;
}

int getFront (int Q[]){
        if (isEmpty()) {
        printf ("Queue is empty\n");
        return;
    }

    return Q[front];
}

void deQueue (int Q[]) {
    if (isEmpty()) {
        printf ("Queue is empty\n");
        return;
    }
    // else if (front > rear) is not correct or prefer sir likse j
    else if(front == rear){
        front = rear = -1;
    }
    else
        front += 1;
}

void Display (int Q[]) {
    if (isEmpty()) {
        printf ("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
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
    
    return 0;
}