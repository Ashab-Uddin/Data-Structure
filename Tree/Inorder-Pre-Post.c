#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Insert a value into the BinaryTree array at a specific index
void Insert(int BinaryTree[], int index, int value) {
    if (index >= MAX || index == -1) {
        printf("Index is out of bound\n");
        return;
    }
    BinaryTree[index] = value;
}

// Display all nodes in the BinaryTree array
void Display(int BinaryTree[]) {
    if (BinaryTree[0] == -1) {
        printf("Tree is empty\n");
        return;
    }
    printf("Displaying the Binary Tree nodes:\n");
    for (int i = 0; i < MAX; i++) {
        if (BinaryTree[i] != -1)
            printf("Node %d: %d\n", i, BinaryTree[i]);
    }
}

// Perform In-order Traversal of the BinaryTree
void InOrderTraverse(int BinaryTree[], int index) {
    if (index >= MAX || index == -1 || BinaryTree[index] == -1) return;

    InOrderTraverse(BinaryTree, 2 * index + 1); // Left child
    printf("%d ", BinaryTree[index]);          // Current node
    InOrderTraverse(BinaryTree, 2 * index + 2); // Right child
}

// Perform Pre-order Traversal of the BinaryTree
void PreOrderTraverse(int BinaryTree[], int index) {
    if (index >= MAX || index == -1 || BinaryTree[index] == -1) return;

    printf("%d ", BinaryTree[index]);          // Current node
    PreOrderTraverse(BinaryTree, 2 * index + 1); // Left child
    PreOrderTraverse(BinaryTree, 2 * index + 2); // Right child
}

// Perform Post-order Traversal of the BinaryTree
void PostOrderTraverse(int BinaryTree[], int index) {
    if (index >= MAX || index == -1 || BinaryTree[index] == -1) return;

    PostOrderTraverse(BinaryTree, 2 * index + 1); // Left child
    PostOrderTraverse(BinaryTree, 2 * index + 2); // Right child
    printf("%d ", BinaryTree[index]);            // Current node
}

int main() {
    int BinaryTree[MAX];
    for (int i = 0; i < MAX; i++) BinaryTree[i] = -1;

    // Insert elements into the binary tree based on the given structure
    Insert(BinaryTree, 0, 1);   // Root
    Insert(BinaryTree, 1, 2);   // Left child of 1
    Insert(BinaryTree, 2, 3);   // Right child of 1
    Insert(BinaryTree, 4, 4);   // Right child of 2
    Insert(BinaryTree, 5, 5);   // Left child of 3
    Insert(BinaryTree, 6, 6);   // Right child of 3
    Insert(BinaryTree, 11, 7);  // Left child of 5
    Insert(BinaryTree, 13, 8);  // Left child of 6
    Insert(BinaryTree, 14, 9);  // Right child of 6

    // Display the tree
    Display(BinaryTree);

    // Perform In-order Traversal
    printf("In-order Traversal: ");
    InOrderTraverse(BinaryTree, 0);
    printf("\n");

    // Perform Pre-order Traversal
    printf("Pre-order Traversal: ");
    PreOrderTraverse(BinaryTree, 0);
    printf("\n");

    // Perform Post-order Traversal
    printf("Post-order Traversal: ");
    PostOrderTraverse(BinaryTree, 0);
    printf("\n");

    return 0;
}
