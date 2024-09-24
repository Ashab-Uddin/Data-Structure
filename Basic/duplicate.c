#include <stdio.h>
int main() {
    int A[100];
    int lb, ub;

    printf("Enter the lb and ub of the array:\n");
    scanf("%d %d", &lb, &ub);

    printf("Input elements of the array:\n");
    for (int i = lb; i <= ub; i++) {
        scanf("%d", &A[i]);
    }

    printf("The Array: ");
    for (int i = lb; i <= ub; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    int dup[100]={0};
    for (int i = lb; i <= ub; i++) {
        for (int j = lb; j <= ub; j++) {
            if (i==j) {
                break;
            }
            else if(A[i]==A[j]){
                dup[i] = 1;
            }            
        }        
    }

    int sum =0;
    for(int i=lb;i<=ub;i++){
            sum +=dup[i];
        
    }
    printf("Total number of duplicate elements: %d\n", sum);

    return 0;
}
