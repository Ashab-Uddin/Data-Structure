#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *top = 0;

void Push() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = top;
    top = newnode;
}

void  Pop(){
    struct node *temp;
    temp = top;

    if(top == NULL){
        printf("Underflow Condition");
    }
    else{
        printf("Pop element is %d",top->data);
        top = top->next;
        free(temp);
    }
}

void Peek(){
    if(top == NULL){
        printf("The list is Empty");
    }
    else{
        printf("Top element is %d",top->data);
    }
}

void display() {
    struct node *temp = top;
    if (top == NULL) {
        printf("The stack is empty\n");
    } else {
        printf("The List: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); 

        switch (choice) {
            case 1:
                Push();
                break;
            case 2:
                Pop();
                break;
            case 3:
                Peek();
                break;
            case 4:
                display();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0); 

    return 0;
}
