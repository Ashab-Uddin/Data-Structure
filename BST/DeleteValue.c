#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrderTraversal(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    inOrderTraversal(node->left);
    printf("%d, ", node->data);
    inOrderTraversal(node->right);
}

TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

TreeNode* delete(TreeNode* node, int data) {
    if (node == NULL) {
        return NULL;
    }

    if (data < node->data) {
        node->left = delete(node->left, data);
    } else if (data > node->data) {
        node->right = delete(node->right, data);
    } else {
        // Node with only one child or no child
        if (node->left == NULL) {
            TreeNode* temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            TreeNode* temp = node->left;
            free(node);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        TreeNode* temp = minValueNode(node->right);

        // Copy the inorder successor's content to this node
        node->data = temp->data;

        // Delete the inorder successor
        node->right = delete(node->right, temp->data);
    }
    return node;
}

int main() {
    TreeNode* root = createNode(13);
    root->left = createNode(7);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(8);
    root->right->left = createNode(14);
    root->right->right = createNode(19);
    root->right->right->left = createNode(18);

    // Traverse
    inOrderTraversal(root);
    printf("\n"); // Creates a new line

    // Delete node 15
    root = delete(root, 15);

    // Traverse
    inOrderTraversal(root);
    printf("\n");

    return 0;
}