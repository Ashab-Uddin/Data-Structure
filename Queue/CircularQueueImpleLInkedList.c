#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front = 0;
struct node *rear = 0;

void enqueue(int x){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;

    if(rear == 0){
        front = rear = newnode;
        rear->next = front;
    }
    else{
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
    // printf("\nEnqueue Data Succesfully");
}
void dequeue(){
    struct node *temp;
    temp = front;
    if(front == 0 && rear == 0){
        printf("The Queue is Empty");
    }
    else if(front == rear){
        front = rear = 0;
        free(temp);
    }
    else{
        front = front->next;
        rear->next = front;
        free(temp);
    }
}
void display(){
    struct node *temp;
    temp = front;

    if(front == 0 && rear == 0){
        printf("The Queue is Empty");
    }
    else{
        while(temp->next != front){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("%d ",temp->data);
    }
}
int main(){
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();
    printf("\n");
    dequeue();
    display();

    return 0;
}