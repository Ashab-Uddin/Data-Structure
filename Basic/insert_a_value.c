#include<stdio.h>
int main(){
    int lb,ub;
    int A[100];
    printf("Enter the lb and ub of the array: "); //lb = lower bound and ub = upper bound
    scanf("%d %d",&lb,&ub);

    printf("Enter the element of an array: ");
    for(int i =lb; i<=ub; i++){
        scanf("%d",&A[i]);
    }

    printf("The Entered Array is: ");
    for(int i =lb; i<=ub; i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    int p;
    printf("Enter the position where you want to insert: ");
    scanf("%d",&p);

    int value;
    printf("Enter the value where you want to insert: ");
    scanf("%d",&value);

    A[p] = value;

    printf("The New array is: ");
    for(int i= lb; i<=ub; i++){
        printf("%d ",A[i]);
    }

    return 0;

}