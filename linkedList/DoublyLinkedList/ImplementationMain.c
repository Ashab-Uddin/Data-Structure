#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL, *tail = NULL;

void createNode() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void insertFirst() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data you want to insert: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL) {
        head = tail = newnode;
    } else {
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}
void insertEnd(){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data you want to insert: ");
    scanf("%d",&newnode->data);

    newnode->prev = NULL;
    newnode->next = NULL;
    if(head == NULL){
        head = tail = newnode;
    }
    else{
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    }
}

void insertSpecificPosition(){
    int pos, i = 1;
    struct node *temp, *newnode;

    printf("Enter the position you want to insert: ");
    scanf("%d", &pos);

    if (pos == 1) {
        insertFirst();
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    temp = head;

    // Traverse to the (pos - 1)th node or until temp becomes NULL
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    // If temp is NULL, the position is out of range
    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newnode);
        return;
    }

        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;

    }


    void  DeleteFromBeg(){
        struct node *temp;
        if(head == NULL){
            printf("The List is Empty");
        }
        else{
        temp = head;
        head = head->next;
        head->prev = NULL;

        //for better perfomance
        /* if (head != NULL) {
            head->prev = NULL;  // Update head's previous pointer
        } else {
            printf("The list is now empty after deletion.\n");
        }*/

        free(temp);  
    }
        
    }

    void DeleteEnd(){
        struct node *temp;
        if(tail == NULL){
            printf("The list is Empty");
        }
        else{
            temp = tail;
            tail->prev->next = NULL;
            tail = tail->prev;
            free(temp);
        }
    }

    void DeleteAny(){
        struct node *temp;
        int pos,i = 1;

        temp = head;
        printf("Enter the position you want to delete: ");
        scanf("%d",&pos);
        if(pos == 1){
            DeleteFromBeg();
            return;
        }
        while(i<pos){
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        
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
        printf("8. Find the length of Linked list\n");
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
            // case 8:
            //     GetLength();
            //     break;
            // case 9:
            //     ReverseList();
            //     break;
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
