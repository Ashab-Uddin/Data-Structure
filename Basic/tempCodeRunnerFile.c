#include<stdio.h>
int main(){
    int A[20][20],B[20][20],C[20][20];
    int i,j, rA, cA, rB, cB;

    printf(" Enter the Number of rows and colums in A Matrix:\n");
    scanf("%d %d",&rA,&cA);
    printf("Enter the Number of rows and colums in B Matrix:\n");
    scanf("%d %d",&rB,&cB);

    printf("Enter the elements of A matrix: \n");
    for(i=0;i<rA;i++){
        for(j=0;j<cA;j++){
            printf("A[%d][%d]= ",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    printf("\n");

    printf("Enter the elements of B matrix: ");
    for(i=0;i<rB;i++){
        for(j=0;j<cB;j++){
            printf("B[%d][%d]= ",i,j);
            scanf("%d",&B[i][j]);
        }
    }
    
    for(i=0;i<rA;i++){
        for(j=0;j<cB;j++){
            C[i][j]= A[i][j]+B[i][j];
        }
    }
    
    printf("Result:\n");
    for(i=0;i<rA;i++){
        for(j=0;j<cB;j++){
            printf("%10d",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}

