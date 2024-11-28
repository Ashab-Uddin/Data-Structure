//Implementation of Queue using array
#include <stdio.h>
#define N 5

int Queue[N];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if (rear == N - 1) {
        printf("The Queue is Full\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        Queue[rear] = x;
    } else {
        rear++;
        Queue[rear] = x;
    }
}

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
    enqueue(2);
    enqueue(5);
    enqueue(-1);

    display();

    return 0;
}
