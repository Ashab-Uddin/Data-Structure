#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List Node Structure
typedef struct InternetPack {
    float internetGB;
    int days;
    float price;
    struct InternetPack *next; // Pointer to the next node
    struct InternetPack *prev; // Pointer to the previous node
} InternetPack;

// Database Structure
typedef struct {
    InternetPack *head;
    InternetPack *tail; // Pointer to the tail for efficient insertions at the end
} InternetDatabase;

// Function Prototypes
void printMainMenu();
void printInternetMenu();
void handleInternetMenu(InternetDatabase *db);
void displayAllInternetPacks(InternetDatabase *db);
void addInternetPack(InternetDatabase *db);
void deleteInternetPack(InternetDatabase *db, float internetGB);
void freeInternetDatabase(InternetDatabase *db);

// Main Function
int main() {
    InternetDatabase internetDb;
    internetDb.head = NULL; // Initialize head
    internetDb.tail = NULL; // Initialize tail

    int choice;

    do {
        printMainMenu();
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                handleInternetMenu(&internetDb);
                break;
            case 9:
                printf("Log Out Successful\n");
                freeInternetDatabase(&internetDb); // Free allocated memory
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 9);

    return 0;
}

// Print Main Menu
void printMainMenu() {
    printf("==== MAIN MENU ====\n");
    printf("1. Internet\n");
    printf("9. Exit\n");
}

// Print Internet Menu
void printInternetMenu() {
    printf("\n==== INTERNET MENU ====\n");
    printf("1. Display All Internet Pack\n");
    printf("2. Add Internet Pack\n");
    printf("3. Delete Internet Pack\n");
    printf("8. Back to Main Menu\n");
}

// Handle Internet Menu
void handleInternetMenu(InternetDatabase *db) {
    int choice;

    do {
        printInternetMenu();
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                displayAllInternetPacks(db);
                break;
            case 2:
                addInternetPack(db);
                break;
            case 3: {
                float internetGB;
                printf("Enter Internet in GB to delete: ");
                scanf("%f", &internetGB);
                deleteInternetPack(db, internetGB);
                break;
            }
            case 8:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 8);
}

// Add Internet Pack
void addInternetPack(InternetDatabase *db) {
    printf("Adding Internet Pack...\n");
    InternetPack *newPack = (InternetPack *)malloc(sizeof(InternetPack));
    if (newPack == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Input data
    printf("Enter Internet in GB: ");
    scanf("%f", &newPack->internetGB);
    printf("Enter Validity Days: ");
    scanf("%d", &newPack->days);
    printf("Enter Price: ");
    scanf("%f", &newPack->price);

    newPack->next = NULL;
    newPack->prev = NULL;

    // Insert at the end of the doubly linked list
    if (db->head == NULL) {
        db->head = newPack;
        db->tail = newPack;
    } else {
        db->tail->next = newPack;
        newPack->prev = db->tail;
        db->tail = newPack;
    }
    printf("Internet Pack Added Successfully!\n");
}

// Display All Internet Packs
void displayAllInternetPacks(InternetDatabase *db) {
    if (db->head == NULL) {
        printf("No Internet Packs Available.\n");
        return;
    }

    InternetPack *temp = db->head;
    printf("==== INTERNET PACKS ====\n");
    while (temp != NULL) {
        printf("Internet: %.2f GB, Validity: %d days, Price: %.2f\n",
            temp->internetGB, temp->days, temp->price);
        temp = temp->next;
    }
}

// Delete Internet Pack
void deleteInternetPack(InternetDatabase *db, float internetGB) {
    if (db->head == NULL) {
        printf("No Internet Packs Available.\n");
        return;
    }

    InternetPack *temp = db->head;
    while (temp != NULL) {
        if (temp->internetGB == internetGB) {
            // If the node to delete is the head
            if (temp == db->head) {
                db->head = temp->next;
                if (db->head != NULL) db->head->prev = NULL;
            }
            // If the node to delete is the tail
            else if (temp == db->tail) {
                db->tail = temp->prev;
                if (db->tail != NULL) db->tail->next = NULL;
            }
            // If the node is in the middle
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            free(temp);
            printf("Internet Pack Deleted Successfully!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Internet Pack not found.\n");
}

// Free the Internet Database
void freeInternetDatabase(InternetDatabase *db) {
    InternetPack *current = db->head;
    while (current != NULL) {
        InternetPack *temp = current;
        current = current->next;
        free(temp);
    }
    db->head = NULL;
    db->tail = NULL;
}
