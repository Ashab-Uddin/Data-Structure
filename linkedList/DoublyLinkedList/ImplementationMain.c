#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL,*temp;

void createNode(){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;

    if(head == NULL){
        head = temp = newnode;
    }
    else{
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }

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
            // case 2:
            //     insertFirst();
            //     break;
            // case 3:
            //     insertEnd();
            //     break;
            // case 4:
            //     insertSpecificPosition();
            //     break;
            // case 5:
            //     DeleteFromBeg();
            //     break;
            // case 6:
            //     DeleteEnd();
            //     break;
            // case 7:
            //     DeleteAny();
            //     break;
            // case 8:
            //     GetLength();
            //     break;
            // case 9:
            //     ReverseList();
            //     break;
            // case 10:
            //     Search();
            //     break;
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
