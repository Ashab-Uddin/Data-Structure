#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 100

// Global variables declaration
int front = -1;
int rear = -1;

// Structure for student information
typedef struct {
    char name[100];
    char purpose[100];
} student;

// Structure for line database
typedef struct {
    student students[SIZE];
} lineDatabase;

// Function prototypes
bool isEmpty();
bool isFull();
void printMainMenu();
void enQueue(lineDatabase *lD);
void deQueue(lineDatabase *lD);
void printDb(lineDatabase *lD);
void countStudents();

int main() {
    lineDatabase lD;

    while (1) {
        printMainMenu();

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            enQueue(&lD);
        } else if (choice == 2) {
            deQueue(&lD);
        } else if (choice == 3) {
            printDb(&lD);
        } else if (choice == 4) {
            countStudents();
        } else if (choice == 5) {
            printf("Exiting program.\n");
            return 0;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Check if the queue is empty
bool isEmpty() {
    return front == -1;
}

// Check if the queue is full
bool isFull() {
    return rear == SIZE - 1;
}

// Main menu function
void printMainMenu() {
    printf("\nMain Menu\n");
    printf("1. Add Students\n");
    printf("2. Serve Students\n");
    printf("3. View Current List\n");
    printf("4. Count Students in Line\n");
    printf("5. Exit.....\n");
    return;
}

// Add a student to the queue
void enQueue(lineDatabase *ld) {
    char name[100];
    char purpose[100];

    if (isFull()) {
        printf("Line is full.\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", name);
    printf("Enter Purpose: ");
    scanf(" %[^\n]", purpose);

    student newSale;
    strcpy(newSale.name, name);
    strcpy(newSale.purpose, purpose);

    ld->students[rear] = newSale;

    printf("Info added successfully.\n");

    return;
}

// Serve (remove) a student from the queue
void deQueue(lineDatabase *ld) {
    if (isEmpty()) {
        printf("Line is empty.\n");
        return;
    }

    printf("Served: %s (%s).\n", ld->students[front].name, ld->students[front].purpose);

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return;
}

// Display the list of students in the queue
void printdb(lineDatabase *ld) {
    if (isEmpty()) {
        printf("Line is empty.\n");
        return;
    }

    printf("Line:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d. %s (%s)\n", i - front + 1, ld->students[i].name, ld->students[i].purpose);
    }
    return;
}

// Count the number of students in the queue
void countStudents() {
    if (isEmpty()) {
        printf("Line is empty.\n");
        return;
    }

    printf("Total Students in Line: %d\n", rear - front + 1);
}
