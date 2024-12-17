#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;

    if(front == 0 && rear == 0){
        front = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
    printf("\nEnqueue Data Successfully\n");
}
void dequeue(){
    struct node *temp;
    if(front == 0 && rear == 0){
        printf("The Queue is Empty");
    }
    else{
        temp = front;
        front = front->next;
        free(temp);

    }
}
void Display(){
    struct node *temp;
    temp = front;
    if(front == NULL && rear == NULL){
        printf("The Queue is Empty\n");
    }
    else{
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}
int main(){
    int choice;
    do{
        printf("\nQueue Implementation Using Linked List\n");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n0. Exit");
        printf("Enter Your Choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                Display();
                break;
            case 0:
                printf("Exiting....");
                break;
            default:
            printf("Invalid Choice! Please Try Again Later");
        }
    }while(choice != 0);

    return 0;
}