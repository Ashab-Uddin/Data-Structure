#include<stdio.h>
int main(){
    int A[10],deletePosintion,n;

    printf("Enter the element number of an array: ");
    scanf("%d",&n);

    printf("Enter the %d number: ",n);
    for(int i =0;i<n;i++){
        scanf("%d",&A[i]);
    }

    printf("Before the delete: ");
    for(int i =0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    printf("Enter the deletePosition: ");
    scanf("%d",&deletePosintion);

    //perform delete
    for(int i =deletePosintion;i<n;i++){
        A[i] = A[i+1];
    }
    n--;

    printf("After delete: ");
    for(int i =0;i<n;i++){
        printf("%d ",A[i]);
    }

    return 0;
}