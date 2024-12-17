#include<stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;
void CreateNode(){
    int data;
    struct node *newnode,*temp;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("\nNode added Successfully\n");
}
void Display(){
    struct node *temp = head;
    if(temp == NULL){
        printf("\nThe Node is Empty\n");
    }
    else{
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Create Node\n2. Display List\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                CreateNode();
                break;
            case 2:
                Display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}