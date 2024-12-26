#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void Insert (int BT[], int index, int value) {
    if (index >= MAX || index < 0) {
        printf ("Index out of bound\n");
        return;
    }
    
    BT[index] = value;
}

void Display (int BT[]) {
    if (BT[0] == -1) {
        printf ("Binary tree is empty\n");
        return;
    }
    
    for (int i = 0; i < MAX; i++) {
        if (BT[i] != -1)
            printf ("Node %d: %d\n", i, BT[i]);
    }
}

int main () {
    int BinaryTree [MAX];
    for (int i = 0; i < MAX; i++) BinaryTree[i] = -1;
    
    Insert (BinaryTree, 0, 5);
    Insert (BinaryTree, 1, 7);
    Insert (BinaryTree, 2, 9);
    Insert (BinaryTree, 3, 11);
    Insert (BinaryTree, 4, 13);
    Insert (BinaryTree, 6, 21);
    
    Display (BinaryTree);
    
    return 0;
}