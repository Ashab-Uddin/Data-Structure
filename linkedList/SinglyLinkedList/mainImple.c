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
    int pos, i = 1;
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter the position to insert the new node: ");
    scanf("%d", &pos);
    printf("Enter data you want to insert at position %d: ", pos);
    scanf("%d", &newnode->data);

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newnode);
    } else {
        newnode->next = temp->next;
        temp->next = newnode; 
    }
}

void DeleteFromBeg(){
    struct node *temp;
    if(head == NULL){
        printf("The list is empty.\n");
    }
    else{
        temp = head;
        head = head->next;
        free(temp);
    }
}
void DeleteEnd(){
    struct node *temp,*prevnode;
    temp = head;
    while(temp->next != 0){
        prevnode = temp;
        temp = temp->next;
    }
    if(temp == head){
        head = NULL;
    }
    else{
        prevnode->next = NULL;
    }
    free(temp);
}
void DeleteAny() {
    struct node *temp, *nextnode;
    int pos, i = 1;
    printf("Enter the position to delete the node: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if (pos == 1) {
        DeleteFromBeg();
        return;
    }

    temp = head;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
    } else {
        nextnode = temp->next;
        temp->next = nextnode->next;
        free(nextnode);
    }
}
void GetLength(){
    struct node *temp;
    int count = 0;
    temp = head;

    if(head == NULL){
        printf("The list is empty\n");
    }
    else{
        while(temp != 0){
            count++;
            temp = temp->next;
        }
        printf("Length is: %d",count);
    }
}

void ReverseList(){
    struct node *prevNode,*currentNode,*nextNode;
    prevNode = NULL;
    currentNode = nextNode = head;
    while(nextNode != 0){
        nextNode = nextNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
}
void Search() {
    struct node *temp;
    int item, position = 1;  // Initialize position to 1 for the head node
    printf("Enter the item you want to search: ");
    scanf("%d", &item);

    temp = head;

    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }

    while (temp != NULL) {
        if (temp->data == item) {
            printf("Item %d is found at position %d\n", item, position);
            return; 
        }
        temp = temp->next;
        position++;
    }
    printf("Item %d is not found in the list.\n", item);
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
        printf("5. Delete from beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete at a specific position\n");
        printf("8. Fint the length of Linked list\n");
        printf("9. Reverse Linked list\n");
        printf("10. Search Item\n");
        printf("11. Display List\n");
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
            case 5:
                DeleteFromBeg();
                break;
            case 6:
                DeleteEnd();
                break;
            case 7:
                DeleteAny();
                break;
            case 8:
                GetLength();
                break;
            case 9:
                ReverseList();
                break;
            case 10:
                Search();
                break;
            case 11:
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
