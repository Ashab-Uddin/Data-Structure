#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

void CreateNode() {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    
    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("\nNode added Successfully\n");
}

void InsertAny() {
    int pos, i, count = 0;
    struct node *newnode, *temp;

    // Count the nodes in the list
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Input position from the user
    printf("Enter the position to insert (starting at 1): ");
    scanf("%d", &pos);

    // Validate position
    if (pos < 1 || pos > count + 1) { // `count + 1` allows insertion at the end
        printf("Invalid Position\n");
        return;
    }

    // Create a new node
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    // Case 1: Insert at the beginning
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
    }
    // Case 2: Insert in the middle or at the end
    else {
        temp = head;
        for (i = 1; i < pos - 1; i++) { // Traverse to the node before the desired position
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    printf("\nNode inserted successfully\n");
}

void DeleteAny() {
    struct node *temp, *nextnode;
    int pos, i = 1;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    // Count the number of nodes and validate position
    int count = 0;
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    if (pos < 1 || pos > count) {
        printf("Invalid position.\n");
        return;
    }

    // Special case: Deleting the head node
    if (pos == 1) {
        temp = head;
        head = head->next;
        free(temp);
        printf("Node deleted successfully.\n");
        return;
    }

    // Traverse to the node before the one to be deleted
    temp = head;
    for (i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    // Adjust pointers and free memory
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);

    printf("Node deleted successfully.\n");
}


void Display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("\nThe List is Empty\n");
        return;
    }
    printf("\nList Elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        
        printf("\n1. Create Node");
        printf("\n2. Display List");
        printf("\n3. Insert Any");
        printf("\n4. Delete Any");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                CreateNode();
                break;
            case 2:
                Display();
                break;
            case 3:
                InsertAny();
                break;
            case 4:
                DeleteAny();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
