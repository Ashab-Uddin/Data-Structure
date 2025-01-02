#include<stdio.h>
#define N 5

int front = -1;
int rear = -1;

int queue[N];

void enqueue(){
    int data;
    printf("Enter data: ");
    scanf("%d",&data);

    if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = data;
    }
    else if((rear+1)%N == front){
            printf("The Queue is Full");
        }
    else{
        rear = (rear+1)%N;
        queue[rear] = data;
    }
    printf("\nEnqueue Element is Successfully");

}
void dequeue(){
    if(front == -1 && rear == -1){
        printf("The Queue is Empty");
    }
    else if(front == rear){
        printf("Dequeue Element is: %d",queue[front]);
        front = rear = -1;
    }
    else{
        printf("Dequeue Element is: %d",queue[front]);
        front = (front+1)%N;

    }
}
void display(){
    int i = front;
    if(front == -1 && rear == -1){
        printf("The Queue is Empty");
    }
    else{
        printf("The Queue Element is: ");
        while(i != rear){
            printf("%d ",queue[i]);
            i = (i+1)%N;
        }
        printf("%d ",queue[rear]);
    }
}

int main(){
    int choice;
    do{
        printf("\nImplementation of Circular Queue Using Array");
        printf("\n1. enqueue");
        printf("\n2. dequeue");
        printf("\n3. display");
        printf("\n0. exit");
        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 0:
            printf("Exiting....");
            break;
            default:
            printf("Invalid Choice! Please Try again");
        }
    }while(choice != 0);

    return 0;
}

