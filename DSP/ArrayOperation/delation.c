#include<stdio.h>
int main(){
    int item;
    int A[] = {1,2,5,3,4,5};
    int size = sizeof(A)/sizeof(A[0]);
    printf("Before Array\n");
    for(int i = 0;i<size; i++){
        printf("%d ",A[i]);
    }
    printf("\nEnter the delete index: ");
    scanf("%d",&item);

    for(int i = item;i<size;i++){
        A[i] = A[i+1];
    }
    size--;

    printf("After Delete\n");
    for(int i = 0;i<size;i++){
        printf("%d ",A[i]);
    }

    return 0;
}