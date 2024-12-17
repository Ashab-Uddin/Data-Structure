#include<stdio.h>
int main(){
    int n,item,pos;
    printf("Enter the size of an array: ");
    scanf("%d",&n);
    int Array[n];
    printf("Enter the %d element of array: ",n);
    for(int i = 0;i<n;i++){
        scanf("%d",&Array[i]);
    }

    printf("Enter the new inserted element : ");
    scanf("%d",&item);

    printf("Enter the position: ");
    scanf("%d",&pos);

    for(int i=n-1; i>=pos;i--){
        Array[i+1] = Array[i];
    }
    Array[pos] = item;
    n++;

    printf("New Array is: \n");
    for(int i=0;i<n;i++){
        printf("%d ",Array[i]);
    }

    return 0;
}