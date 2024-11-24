#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct MyPack {
    int internets;
    int minute;
    int voice
    int day;
    int balance;
    struct MyPack *next; // Pointer to the next node in the list
} MyPack;

typedef struct {
    MyPack *head;
} PacksDatabase;

void printMainMenu();
void Internet(PacksDatabase *db); // Pass SalesDatabase by reference
void Bundles(PacksDatabase *db); // Pass SalesDatabase by reference
void Minutes(PacksDatabase *db);
void My_Offers(PacksDatabase *db);
void EasyPlan(PacksDatabase *db);
// void Balance(PacksDatabase *db);
void Search(PacksDatabase *db);
void display(PacksDatabase *db);
void SaleCount(PacksDatabase *db);
MyPack* createNode();

int main() {
    PacksDatabase db; // Database with linked list
    db.head = NULL;   // Initialize head to NULL

    int choice;

    do {
        printMainMenu();
        printf("\n\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                Internet(&db);
                break;
            case 2:
                Minutes(&db);
                break;
            case 3:
                EasyPlan(&db);
                break;
            case 4:
                display(&db);
                break;
            case 5:
                printf("Log Out Successful\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5); // Exit loop if choice is 9

    return 0;
}
