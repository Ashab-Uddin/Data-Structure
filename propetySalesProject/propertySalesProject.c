#include <stdio.h>
#include <string.h>


// Structure for sales information
typedef struct {
    int uid;
    char address[100];
    int zip;
    int size;
    int year;
    int price;
} PropertySale;

// Structure for sales information database
typedef struct {
    PropertySale sales[100];
    int salesCount;
} propertySalesDatabase;


void printMainMenu();
void Sales(propertySalesDatabase *db);
void Erase(propertySalesDatabase *db);
void Search(propertySalesDatabase *db);
void PrintDB(propertySalesDatabase *db);
void GetZIP(propertySalesDatabase *db);
void GetPrice(propertySalesDatabase *db);
void SaleCount(propertySalesDatabase *db);
int AveragePrice(propertySalesDatabase *db);
void SortByPriceInAsc(propertySalesDatabase *db);
void SortByPriceInDesc(propertySalesDatabase *db);
void SortInDefinedRange(propertySalesDatabase *db);


int main() {
    int option,pass;
    propertySalesDatabase db; // Declaring pointer to access database
    db.salesCount = 0;  // Declaring salesCount

    printf("\nPASSWORD: ");
    scanf("%d", &pass);
    for(;pass!=274;){
        printf("Invalid Password!\n");
        printf("\nPASSWORD: ");
        scanf("%d", &pass);
    }

    for(;pass==274;){
        printMainMenu();
        printf("\n\nENTER YOUR CHOICE: ");
        scanf("%d", &option);
        printf("\n");

        if (option==1) {
                Sales(&db);    // Insert a new sale information
                }
        else if (option==2){
                Erase(&db);    // Delete a sale information
                }
        else if (option==3){
                Search(&db);   // Search for a sale information
                }
        else if (option==4){
                PrintDB(&db);  // Print the database of sale information
                }
        else if (option==5){
                GetZIP(&db);   // print sales information get ZIP Code
                }
        else if (option==6){
                GetPrice(&db);  // print sales information get price
                }
        else if (option==7){
                AveragePrice(&db); // print average price of sales property
                }
        else if (option==8){
                SaleCount(&db); // print total sales
                }
        else if (option==9){
                SortByPriceInAsc(&db); // perform for sort by ascending order
                }
        else if (option==10){
                SortByPriceInDesc(&db); //perform for sort by descending order
                }
        else if (option==11){
                SortInDefinedRange(&db);  // perform for sort by range
                }
        else if (option==12){
                break;          
                }
        else{
            printf("Invalid choice. Please try again.\n");
            }
    }
    printf("Log Out Successful\n");
    return 0;
}



// Main  fuction
void printMainMenu() {
    printf("\nMain Menu:\n");
    printf("1. Insert new flat sale information\n");
    printf("2. Delete a property from the system\n");
    printf("3. Find a property from the system\n");
    printf("4. See all properties\n");
    printf("5. Get zip code\n");
    printf("6. Price\n");
    printf("7. Average prices of sales property\n");
    printf("8. Total sales\n");
    printf("9. Sort by ascending order\n");
    printf("10. Sort by descending order\n");
    printf("11. Sort by range\n");
    printf("12. Log Out\n");
}


// Function for insert a new sale information
void Sales(propertySalesDatabase *db) {
        int uid, zip, year, price;
        float size;
        char address[100];

        printf("Enter UID: ");
        scanf("%d", &uid);
        printf("Enter Address: ");
        scanf(" %[^\n]s", address);
        printf("Enter ZIP code: ");
        scanf("%d", &zip);
        printf("Enter size: ");
        scanf("%f", &size);
        printf("Enter construction year: ");
        scanf("%d", &year);
        printf("Enter price: ");
        scanf("%d", &price);

        PropertySale newSale = {uid, "", zip, size, year, price};
        strcpy(newSale.address, address);

        db->sales[db->salesCount] = newSale;
        db->salesCount++;

        printf("Sale added successfully.\n");
    }


// Function for delete a sold property
void Erase(propertySalesDatabase *db) {
    int uid,count=0;
    printf("Enter the UID to delete: ");
    scanf("%d", &uid);

    for (int i = 0; i < db->salesCount; i++) {
        if (db->sales[i].uid == uid) {
            for (int j = i; j < db->salesCount-1; j++) {
                db->sales[j] = db->sales[j + 1];
            }
            db->salesCount--;
            printf("Sale with UID %d deleted successfully.\n", uid);
            count=1;  
        }
    }
    if(count==0){
        printf("Sale with UID %d not found.\n", uid);
    }
}


// Function for search sold property
void Search(propertySalesDatabase *db) {
    int uid,count=0;;
    printf("Enter the UID to search for: ");
    scanf("%d", &uid);

    for (int i = 0; i < db->salesCount; i++) {
        if (db->sales[i].uid == uid) {
            printf("Sale found: UID=%d, Address=%s, ZIP=%d, Size=%d, Year=%d, Price=%d\n",
            db->sales[i].uid, db->sales[i].address, db->sales[i].zip,
            db->sales[i].size, db->sales[i].year, db->sales[i].price);
            count = 1;  // To marke property is found
        }
    }

    if (count==0) {
        printf("Sale with UID %d not found.\n", uid);
    }
}


// Function for print all sales database
void PrintDB(propertySalesDatabase *db) {
    if (db->salesCount == 0) {
        printf("No sales available.\n");
        return;
    }

    for (int i = 0; i < db->salesCount; i++) {

        printf("UID: %d, Address: %s, ZIP: %d, Size: %d, Year: %d, Price: %d\n",
        db->sales[i].uid, db->sales[i].address, db->sales[i].zip,
        db->sales[i].size, db->sales[i].year, db->sales[i].price);
    }
}


// Function for print property get zip code 
void GetZIP(propertySalesDatabase *db) {
    int uid,count=0;;
    printf("Enter the UID: ");
    scanf("%d", &uid);

    for (int i = 0; i < db->salesCount; i++) {
        if (db->sales[i].uid == uid) {
            printf("Zip Code: %d\n", db->sales[i].zip);
            count = 1;  // To marke zip code is found
        }
    }

    if (count==0) {
        printf("Zip code with UID %d not found.\n", uid);
    }
}


// Function for find price in property
void GetPrice(propertySalesDatabase *db) {
    int uid,count=0;;
    printf("Enter the UID: ");
    scanf("%d", &uid);

    for (int i = 0; i < db->salesCount; i++) {
        if (db->sales[i].uid == uid) {
            printf("Price: %d\n", db->sales[i].price);
            count = 1;  // To marke price is found
        }
    }

    if (count==0) {
        printf("Price with UID %d not found.\n", uid);
    }
}


// Function for print  average price of sales
int AveragePrice(propertySalesDatabase *db) {
    if (db->salesCount == 0) {
        printf("Average price of sales: 0.00\n");
        return 0;
    }

    float avg,totalPrice = 0;
    for (int i = 0; i < db->salesCount; i++) {
        totalPrice += db->sales[i].price;
    }
    avg = totalPrice / db->salesCount;
    printf("Average price of sales: %.2f\n",avg);
    return 0;
}


// Fuction for print total sales
void SaleCount(propertySalesDatabase *db) {
    int sales=db->salesCount;
    printf("Total sales: %d\n",sales);
}

// Function for sort ascending order using selection sort technique
void SortByPriceInAsc(propertySalesDatabase *db) {
    for (int i = 0; i < db->salesCount - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < db->salesCount; j++) {
            if (db->sales[j].price < db->sales[minIndex].price) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            PropertySale temp = db->sales[i];
            db->sales[i] = db->sales[minIndex];
            db->sales[minIndex] = temp;
        }
    }
    printf("Properties sorted successfully in ascending order by price.\n");
}



// Function for  sort descending order using bubble sort technique
void SortByPriceInDesc(propertySalesDatabase *db) {
    for (int i = 0; i < db->salesCount - 1; i++) {
        for (int j = 0; j < db->salesCount - i - 1; j++) {
            if (db->sales[j].price < db->sales[j + 1].price) {
                PropertySale temp = db->sales[j];
                db->sales[j] = db->sales[j + 1];
                db->sales[j + 1] = temp;
            }
        }
    }
    printf("Properties sorted successfully in descending order.\n");
}

// Function for sort by range using insertion sort technique
void SortInDefinedRange(propertySalesDatabase *db) {
    int lowerprice, upperprice;
    printf("Enter the price range (lower upper):\n");
    scanf("%d %d", &lowerprice, &upperprice);

    // Temporary arrays to separate and store elements that are within and outside the specified range
    PropertySale propertiesWithinRange[db->salesCount];
    int inRangeCount = 0; 
    PropertySale propertiesOutSideOfRange[db->salesCount];
    int outOfRangeCount = 0; 

   //properties according to their price within the defined range
    for (int i = 0; i < db->salesCount; i++) {
        if (db->sales[i].price >= lowerprice && db->sales[i].price <= upperprice) {
            propertiesWithinRange[inRangeCount++] = db->sales[i];
        } else {
            propertiesOutSideOfRange[outOfRangeCount++] = db->sales[i]; 
        }
    }

    // Sort the properties within the defined range using insertion sort technique
    for (int i = 1; i < inRangeCount; i++) {
        PropertySale currentProperty = propertiesWithinRange[i];
        int j = i - 1;

        while (j >= 0 && propertiesWithinRange[j].price > currentProperty.price) {
            propertiesWithinRange[j + 1] = propertiesWithinRange[j];
            j--;
        }
        propertiesWithinRange[j + 1] = currentProperty;
    }

    printf("\nProperties sorted successfully within the specified price range.\n\n");

    // Prompt user to display the sorted results
    int userChoice;
    printf("**************************\n");
    printf("Press 0 to see the results\n");
    printf("**************************\n");
    scanf("%d", &userChoice);

    if (userChoice == 0) {
        // Display properties within the defined range
        for (int i = 0; i < inRangeCount; i++) {
            printf("UID: %d, Address: %s, ZIP: %d, Size: %d, Year: %d, Price: %d\n",
                propertiesWithinRange[i].uid, propertiesWithinRange[i].address, propertiesWithinRange[i].zip,
                propertiesWithinRange[i].size, propertiesWithinRange[i].year, propertiesWithinRange[i].price);
        }

        // Display properties outside the defined range
        for (int i = 0; i < outOfRangeCount; i++) {
            printf("UID: %d, Address: %s, ZIP: %d, Size: %d, Year: %d, Price: %d\n",
                propertiesOutSideOfRange[i].uid, propertiesOutSideOfRange[i].address, propertiesOutSideOfRange[i].zip,
                propertiesOutSideOfRange[i].size, propertiesOutSideOfRange[i].year, propertiesOutSideOfRange[i].price);
        }
    }
}