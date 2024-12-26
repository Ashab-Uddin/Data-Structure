#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void Insert (int BinaryTree[], int index, int value) {
    if (index >= MAX || index == -1) {
        printf ("Index is out of bound\n");
        return;
    }
    
    BinaryTree[index] = value;
}

void Display (int BinaryTree[]) {
    if (BinaryTree[0] == -1) {
        printf ("Tree is empty\n");
        return;
    }
    
    for (int i = 0; i < MAX; i++) {
        if (BinaryTree[i] != -1) 
            printf ("Node %d: %d\n", i, BinaryTree[i]);
    }
}

void InOrderTraverse (int BinaryTree[], int index) {
    if (index >= MAX || index == -1) return;
    
    InOrderTraverse (BinaryTree, 2 * index + 1);
    InOrderTraverse (BinaryTree, 2 * index + 2);
    if (BinaryTree[index] != -1) printf ("%d ", BinaryTree[index]);
}

int main () {
    int BinaryTree [MAX];
    for (int i = 0; i < MAX; i++) BinaryTree[i] = -1;
    
    Insert (BinaryTree, 0, 5);
    Insert (BinaryTree, 1, 7);
    Insert (BinaryTree, 2, 8);
    Insert (BinaryTree, 3, 12);
    Insert (BinaryTree, 4, 15);
    Insert (BinaryTree, 6, 19);
    
    Display (BinaryTree);
    
    InOrderTraverse (BinaryTree, 0);
    printf ("\n");
    
    return 0;
}