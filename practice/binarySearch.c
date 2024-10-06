#include<stdio.h>
int main(){
    int A[] = {3,5,7,8,9,23,56,67,89,94,95,97,99};

    int length= sizeof(A) / sizeof(A[0]);

    printf("Before Sorting: ");
    for(int i =0;i<length;i++){
        printf("%d ",A[i]);
    }

    printf("\n");
}
