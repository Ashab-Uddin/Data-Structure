#include <stdio.h>
#include <string.h>

#define SIZE 100

// Global variables declaration
int front = -1;
int rear = -1;

// Structure for student information
typedef struct {
    char name[SIZE];
    char purpose[SIZE];
} student;

// Structure for line database
typedef struct {
    student studentsinfo[SIZE];
} lineDatabase;

// Function prototypes
int isEmpty();
int isFull();
void printMainMenu();
void enQueue(lineDatabase *lD);
void deQueue(lineDatabase *lD);
void printDb(lineDatabase *lD);
void countStudents();

int main() {
    lineDatabase lD = {0}; // Initialize all students to default values

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
            printf("Exiting program...\n");
            return 0;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Check if the queue is empty
int isEmpty() {
    return (front == -1) ? 1 : 0; // Return 1 for true (empty), 0 for false (not empty)
}

// Check if the queue is full
int isFull() {
    return (rear == SIZE - 1) ? 1 : 0; // Return 1 for true (full), 0 for false (not full)
}

// Main menu function
void printMainMenu() {
    printf("\n====== Main Menu ======\n");
    printf("1. Add Students\n");
    printf("2. Serve Students\n");
    printf("3. View Current Student List\n");
    printf("4. Total Students in Line\n");
    printf("5. Exit...\n");
    return;
}

// Add a student to the queue
void enQueue(lineDatabase *lD) {
    char name[SIZE];
    char purpose[SIZE];

    if (isFull()) {
        printf("The line is full. Cannot add more students.\n");
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

    student newStudent; 
    strcpy(newStudent.name, name);
    strcpy(newStudent.purpose, purpose);

    lD->studentsinfo[rear] = newStudent;

    printf("Student information added successfully.\n");
    return;
}

// Serve (remove) a student from the queue
void deQueue(lineDatabase *lD) {
    if (isEmpty()) {
        printf("The line is empty. No students to serve.\n");
        return;
    }

    printf("Served: %s (%s).\n", lD->studentsinfo[front].name, lD->studentsinfo[front].purpose);

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return;
}

// Display the list of students in the queue
void printDb(lineDatabase *lD) {
    if (isEmpty()) {
        printf("The line is Empty. No students in the Queue.\n");
        return;
    }

    printf("Current Students in Line:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d. %s (%s)\n", i - front + 1, lD->studentsinfo[i].name, lD->studentsinfo[i].purpose);
    }
    return;
}

// Count the number of students in the queue
void countStudents() {
    if (isEmpty()) {
        printf("The line is Empty. No students in line.\n");
        return;
    }

    printf("Total Students in Line: %d\n", rear - front + 1);
}