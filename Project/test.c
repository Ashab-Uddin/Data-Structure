#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure for sales info
typedef struct PropertySale {
    int uid;
    char address[100];
    int zip;
    int size;
    int year;
    int price;
    struct PropertySale *next; // Pointer to the next node in the list
} PropertySale;

PropertySale *head;
// Structure for sales database (only head pointer for the linked list)
// typedef struct {
//     PropertySale *head;
// } SalesDatabase;

// void printMainMenu();
// void Sales(SalesDatabase *db); // Pass SalesDatabase by reference
// void Erase(SalesDatabase *db); // Pass SalesDatabase by reference
// void Search(SalesDatabase *db);
// void PrintDB(SalesDatabase *db);
// void GetZIP(SalesDatabase *db);
// void GetPrice(SalesDatabase *db);
// void AveragePrice(SalesDatabase *db);
// void SaleCount(SalesDatabase *db);
// PropertySale* createNode();


// Main menu function
void printMainMenu(void) {
    printf("\nMain Menu:\n");
    printf("1. Insert new flat sale information\n");
    printf("2. Delete a property from the system\n");
    printf("3. Find a property from the system\n");
    printf("4. See all properties\n");
    printf("5. Get zip code\n");
    printf("6. Price\n");
    printf("7. Average prices of sales property\n");
    printf("8. Total sales\n");
    printf("9. Log Out\n");
    printf("..........");
}

// Create a new node for a sale entry
PropertySale* createNode() {
    PropertySale *newNode = (PropertySale *)malloc(sizeof(PropertySale));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit if memory allocation fails
    }
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new sale info into the database
void Sales(SalesDatabase *db) {
    PropertySale *newSale = createNode();

    printf("Enter UID: ");
    scanf("%d", &newSale->uid);
    printf("Enter Address: ");
    scanf(" %[^\n]s", newSale->address);
    printf("Enter ZIP code: ");
    scanf("%d", &newSale->zip);
    printf("Enter size: ");
    scanf("%d", &newSale->size);
    printf("Enter construction year: ");
    scanf("%d", &newSale->year);
    printf("Enter price: ");
    scanf("%d", &newSale->price);

    // Insert the new node at the beginning of the list (linked list insert)
    newSale->next = db->head;
    db->head = newSale;

    printf("Sale added successfully.\n");
}

// Function to delete a sold property info from the database
void Erase(SalesDatabase *db) {
    if (db->head == NULL) {
        printf("The database is empty. Nothing to delete.\n");
        return;
    }

    int uid;
    printf("Enter the UID to delete: ");
    scanf("%d", &uid);

    PropertySale *current;

    // Special case: deleting the first node
    if (db->head != NULL && db->head->uid == uid) {
        current = db->head;
        db->head = current->next;  // Update head to the next node
        free(current);  // Free the old head node
        printf("Sale with UID %d deleted successfully.\n", uid);
        return;
    }

    PropertySale *temp = db->head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->uid == uid) {
            current = temp->next;
            temp->next = current->next;
            free(current);
            printf("Sale with UID %d deleted successfully.\n", uid);
            return;
        }
        temp = temp->next;
    }

    printf("Sale with UID %d not found.\n", uid);
}

// Function to search for a sold property in the database
void Search(SalesDatabase *db) {
    int uid;
    printf("Enter the UID to search for: ");
    scanf("%d", &uid);

    PropertySale *temp = db->head;
    while (temp != NULL) {
        if (temp->uid == uid) {
            printf("Sale found: UID=%d, Address=%s, ZIP=%d, Size=%d, Year=%d, Price=%d\n",
                    temp->uid, temp->address, temp->zip,
                    temp->size, temp->year, temp->price);
            return;
        }
        temp = temp->next;
    }
    printf("Sale with UID %d not found.\n", uid);
}

// Function to print the sales database
void PrintDB(SalesDatabase *db) {
    if (db->head == NULL) {
        printf("No sales available.\n");
        return;
    }

    PropertySale *temp = db->head;
    while (temp != NULL) {
        printf("UID: %d, Address: %s, ZIP: %d, Size: %d, Year: %d, Price: %d\n",
                temp->uid, temp->address, temp->zip,
                temp->size, temp->year, temp->price);
        temp = temp->next;
    }
}

// Function to get zip code for a property
void GetZIP(SalesDatabase *db) {
    int uid;
    printf("Enter the UID: ");
    scanf("%d", &uid);

    PropertySale *temp = db->head;
    while (temp != NULL) {
        if (temp->uid == uid) {
            printf("Zip Code: %d\n", temp->zip);
            return;
        }
        temp = temp->next;
    }
    printf("Zip code with UID %d not found.\n", uid);
}

// Function to get price of a property
void GetPrice(SalesDatabase *db) {
    int uid;
    printf("Enter the UID: ");
    scanf("%d", &uid);

    PropertySale *temp = db->head;
    while (temp != NULL) {
        if (temp->uid == uid) {
            printf("Price: %d\n", temp->price);
            return;
        }
        temp = temp->next;
    }
    printf("Price with UID %d not found.\n", uid);
}

// Function to calculate average price of sales
void AveragePrice(SalesDatabase *db) {
    if (db->head == NULL) {
        printf("Average price of sales: 0.00\n");
        return;
    }

    int count = 0, totalPrice = 0;
    PropertySale *temp = db->head;

    while (temp != NULL) {
        totalPrice += temp->price;
        count++;
        temp = temp->next;
    }

    float avg = (float)totalPrice / count;
    printf("Average price of sales: %.2f\n", avg);
}

// Function to count total sales in the database
void SaleCount(SalesDatabase *db) {
    int count = 0;
    PropertySale *temp = db->head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total sales: %d\n", count);
}

int main() {
    // SalesDatabase db; // Database with linked list
    // db.head = NULL;   // Initialize head to NULL

    int choice;

    while (1) {
        printMainMenu();
        printf("\n\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        printf("\n");
    
        if (choice == 1) {
            Sales(&db); // Pass the database by reference
        } else if (choice == 2) {
            Erase(&db); // Pass the database by reference
        } else if (choice == 3) {
            Search(&db); // Pass the database by reference
        } else if (choice == 4) {
            PrintDB(&db); // Pass the database by reference
        } else if (choice == 5) {
            GetZIP(&db);
        } else if (choice == 6) {
            GetPrice(&db);
        } else if (choice == 7) {
            AveragePrice(&db);
        } else if (choice == 8) {
            SaleCount(&db);
        } else if (choice == 9) {
            printf("Log Out Successful\n");
            exit(0);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

