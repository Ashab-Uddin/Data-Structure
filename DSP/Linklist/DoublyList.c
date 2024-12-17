#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
struct node *tail = NULL;

void CreateNode(){
    struct node *newnode,*temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;

    if(head == NULL){
        head = tail = newnode;
    }
    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
        
    }
    printf("\nCreate Node Successfully\n");
}
void InserFirst(){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter the Data: ");
    scanf("%d",&newnode->data);

    newnode->next = NULL;
    newnode->prev = NULL;

    if(head == NULL){
        head = tail = newnode;
    }
    else{
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
    printf("\nInsert Successfully\n");
}
void Display(){
    struct node *temp;
    temp = head;
    printf("The Elements: ");
    while(temp != 0){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
int main(){
    int choice;
    do{
        printf("\n1. Create New node");
        printf("\n2. Display");
        printf("\n3. Insert First");
        printf("\n0. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                CreateNode();
                break;
            case 2:
                Display();
                break;
            case 3:
                InserFirst();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
            printf("Invalid Choice!");
        }
    }while(choice != 0);

    return 0;

}