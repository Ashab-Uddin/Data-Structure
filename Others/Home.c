#include<stdio.h>
struct PropertySale{
    int uid,zip,year;
    float size,price;
    char address[50];
}pop[100];
int t = -1;
void insert(){
    printf("Enter your Property Information: ");
    printf("Enter Your UID: ");
    scanf("%d",&pop[t].uid);

    printf("Enter Address: ");
    scanf("%s",pop[t].address);

    printf("Enter ZIP code: ");
    scanf("%d",&pop[t].zip);

    printf("Enter Size: ");
    scanf("%f",&pop[t].size);
    
    printf("Enter Constraction Year: ");
    scanf("%d",&pop[t].year);

    printf("Enter Price: ");
    scanf("%f",&pop[t].price);

}
int main(){
    int n;
    do{
        printf("
        \n1.Insert New Flat Sale Information
        \n2.Delete a Property From the System
        \n3.Search A Property From the System
        \n4.View All Properties
        \n5.Get ZIP Code of a Property
        \n6.Get Price of a Property
        \n7.Average Price of All Properties
        \n8.Total Sales
        \n9.EXIT
        \nEnter your option: ");
        scanf("%d",&n);
        if(n==1)
            insert();
        else if(n==2)
            search();
        else if(n==3)
            delete();
        else if(n==4)
            view();
        else if(n==5)
            zip();
        else if(n==6)
            price();
        else if(n==7)
            average_price();
        else if(n==8)
            total_sale();

    }while(n<9);

    return 0;

}