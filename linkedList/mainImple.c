#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *next;
};

// Global head pointer
struct node *head = NULL;

// Function to create and add a new node to the linked list
void createNode() {
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    

    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head =  newnode; 
    } else {
        temp = head;
        while (temp->next != NULL) {  
            temp = temp->next;
        }
        temp->next = newnode; 
    }
}
void insertFirst(){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data you want to insert: ");
    scanf("%d",&newnode->data);
    newnode->next = head;
    head = newnode;
}
void insertEnd(){
    struct node *newnode,*temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data you want to insert: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    temp = head;

    while(temp->next != 0){
        temp = temp->next;
    }
    temp->next = newnode;

}
void insertSpecificPosition(){
    int pos,int i =1;
    struct node *newnode,*temp;
    printf("Enter the Position: ");
    scanf("%d",&pos);

}

// Function to display the linked list
void displayList() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Create new node\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at the End\n");
        printf("4. Insert at a specific position\n");
        printf("5. Display List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); 

        switch (choice) {
            case 1:
                createNode();
                break;
            case 2:
                insertFirst();
                break;
            case 3:
                insertEnd();
                break;
            case 4:
                insertSpecificPosition();
                break;
            case 4:
                displayList();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0); 


    displayList();  
    
    return 0;
}
