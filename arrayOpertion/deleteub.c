#include<stdio.h>
int main(){
    int lb,ub,index,value;
    int A[20];

    printf("Enter the lb of an array: ");
    scanf("%d",&lb);
    
    printf("Enter the up of an array: ");
    scanf("%d",&ub);

    printf("Enter the elements of an array: ");
    for (int i=lb; i<=ub; i++){
        scanf("%d",&A[i]);
    }
    printf("\n");

    printf("The array is: ");
    for(int i=1; i<=5; i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    printf("Enter the indext you want to delete: ");
    scanf("%d",&index);

    for (int j = index; j<ub; j++){
        A[j] = A[j+1];
        
    }
    ub -=1;
    printf("Final array is: ");
    for (int i =lb;i<=ub;i++){
        printf("%d ",A[i]);
    }
    return 0;
}