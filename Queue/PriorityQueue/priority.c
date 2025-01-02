#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

int rear = -1;

struct Node {
    int value;
    int priority;
};

struct Node PQ[SIZE];

bool isEmpty () {
    if (rear == -1) return true;
    else return false;
}

bool isFull () {
    if (rear == SIZE - 1) return true;
    else return false;
}

void enQueue (int v, int p) {
    if (isFull()) {
        printf ("Queue is full\n");
        return;
    }
    
    rear += 1;
    PQ[rear].value = v;
    PQ[rear].priority = p;
}



int getIndexofHP () {
    int p = PQ[0].priority;
    int idx = 0;
    
    for (int i = 1; i <= rear; i++) {
        if (p < PQ[i].priority) {
            p = PQ[i].priority;
            idx = i;
        }
    }
    
    return idx;
} 

void deQueue () {
    if (isEmpty()) {
        printf ("Queue is empty\n");
        return;
    }
    
    int idx = getIndexofHP();
    for (int j = idx; j < rear; j++) {
        PQ[j].value = PQ[j+1].value;
        PQ[j].priority = PQ[j+1].priority;
    }
    rear -= 1;
}
void display () {
    if (isEmpty()) {
        printf ("Queue is empty\n");
        return;
    }
    
    for (int i = 0; i <= rear; i++) 
        printf ("%d %d\n", PQ[i].value, PQ[i].priority);
}


int main () {
    enQueue (34, 2);
    enQueue (53, 3);
    enQueue (98, 1);
    display ();
    printf ("Index of Highest Priority: %d\n", getIndexofHP()); 
    deQueue ();
    display ();
    deQueue ();
    printf("\n");
    display ();
    return 0;
}