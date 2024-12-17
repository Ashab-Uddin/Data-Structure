#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int top = -1;

void Push (int Stack[], int item) {
    if (top == SIZE) {
        printf ("Overflow\n");
        return;
    }
    
    top += 1;
    Stack[top] = item;
}

int Pop (int Stack[]) {
    if (top < 0) {
        printf ("Underflow\n");
        exit(0);
    }
    
    int item = Stack[top];
    top -= 1;
    return item;
}

int main () {
    int Stack[SIZE];
    Push (Stack, 10);
    Push (Stack, 20);
    Push (Stack, 30);
    Push (Stack, 40);
    printf ("%d\n", Pop (Stack));
    printf ("%d\n", Pop (Stack));
    printf ("%d\n", Pop (Stack));
    printf ("%d\n", Pop (Stack));
        
    return 0;
}