#include<stdio.h>
#define N 5

int Q[N];
int front = -1;
int rear = -1;

void enqueue(int x){
    if(front == -1 && rear == -1){
        front = rear = 0;
        Q[rear] = x;
    }
    else if((rear+1)%N == front){
        printf("Full");
    }
    else{
        rear = (rear+1)%N;
        Q[rear] = x;
    }
}
void dequeue(){
    if(front == -1 && rear == -1){
        printf("Empty");
    }
    else if(front == rear){
        front=rear=-1;
    }
    else{
        front = (front+1)%N;
    }
}
void display(){
    int i = front;
    if(front == -1 && rear == -1){
        printf("Empty");
    }
    else{
        while(i != rear){
            printf("%d ",Q[i]);
            i = (i+1)%N;
        }
        printf("%d ",Q[rear]);
    }
}
int main(){
    enqueue(2);
    enqueue(4);
    display();
    dequeue();
    printf("\n");
    display();
}