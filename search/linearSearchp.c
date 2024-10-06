#include<stdio.h>
int linearSearch(int A[],int item, int n){
    int i;
    for (int i =0;i<n;i++){
        if(A[i] == item){
            printf("Item is found at index: %d ",i);
            break;
        }
    }
    if(i == n){
        printf("Item is not found");
    }
}
int main(){
    int A[20],item,n;
    int result;
    
    printf("Enter the size of an array:");
    scanf("%d",&n);

    printf("Enter the %d element for this array: ",n);
    for(int i =0;i<n;i++){
        scanf("%d",&A[i]);
    }

    printf("The Entered Array is: ");
    for (int i =0;i<n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    printf("Enter the searching item: ");
    scanf("%d",&item);

    linearSearch(A,item,n);

}