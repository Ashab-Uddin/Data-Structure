#include <stdio.h>
#define N 5

int stack[N];
int top = -1;

void push() {
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);

    if (top == N - 1) {
        printf("Overflow Condition\n");
    } else {
        top++;
        stack[top] = data;
    }
}

void Pop() {
    int item;
    if (top == -1) {
        printf("Underflow Condition\n");
    } else {
        item = stack[top];
        top--;
        printf("Pop item is %d\n", item);
    }
}

void Peek(){
    if(top == -1){
        printf("The Stack is Empty");
    }
    else{
        printf("Top most element of Stack is %d",stack[top]);
    }
}
void Display(){
    for(int i = top; i>=0; i--){
        printf("%d ",stack[i]);
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
                push();
                break;
            case 2:
                Pop();
                break;
            case 3:
                Peek();
                break;
            case 4:
                Display();
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
