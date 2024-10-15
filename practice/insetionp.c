#include<stdio.h>
int main(){
    int A[20],value,position,n;

    printf("Enter the number of array element: ");
    scanf("%d",&n);

    printf("Enter the %d number: ",n);
    for(int i = 0;i<n;i++){
        scanf("%d",&A[i]);
    }

    printf("Before insert: ");
    for(int i =0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    printf("Enter the position: ");
    scanf("%d",&position);

    printf("Enter the value: ");
    scanf("%d",&value);

    //int length = sizeof(A)/sizeof(A[0]);

    //perform the insetion

    for(int i =n-1;i>=position;i-- ){
        A[i+1] = A[i];
    }
    A[position] = value;
    n++;

    printf("After insert: ");
    for(int i =0;i<n;i++){
        printf("%d ",A[i]);
    }

    return 0;
}