#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for malloc

struct node {
    int data;
    struct node *left, *right;
};

// Function to create a binary tree
struct node *create() {
    struct node *newnode;
    int x;

    // Allocate memory for the new node
    newnode = (struct node *)malloc(sizeof(struct node));

    // Ask for data
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);

    // If input is -1, no node is created
    if (x == -1) {
        free(newnode); // Free allocated memory to prevent memory leaks
        return NULL;
    }

    // Assign data to the current node
    newnode->data = x;

    // Create the left and right subtrees recursively
    printf("Enter left child of %d: ", x);
    newnode->left = create();

    printf("Enter right child of %d: ", x);
    newnode->right = create();

    return newnode;
}

int main() {
    struct node *root = NULL; // Initialize the root
    root = create();          // Create the binary tree
    return 0;                 // Standard return value for main
}
