#include<stdio.h>
int main(){
    int lb,ub;
    int A[100];

    printf("Enter the lb: ");
    scanf("%d",&lb);

    printf("Enter the ub: ");
    scanf("%d",&ub);

    printf("Enter the element of an array: ");
    for(int i = lb; i<=ub; i++){
        scanf("%d",&A[i]);
    }

    printf("The array is: ");
    for (int i=lb; i<=ub; i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    int p;
    printf("Enter the position you want to delete: ");
    scanf("%d",&p);

    for(int i =p; i<=ub; i++){
        A[i] = A[i+1];
    }
    ub --;


    printf("The New array is: ");
    for(int i =lb; i<=ub; i++){
        printf("%d ",A[i]);
    }
    return 0;
}