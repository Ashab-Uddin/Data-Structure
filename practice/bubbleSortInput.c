#include<stdio.h>
void bubbleSortInput(int A[],int n){
    int flag,temp;
    for(int i =0;i<n-1;i++){
        flag =0;
        for(int j=0;j<n-1-i;j++){
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}
int main(){
    int A[30],n;
    printf("Enter the size of an array: ");
    scanf("%d",&n);

    printf("Enter the %d element : ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }


    printf("Array Before Sorting: ");
    for(int i =0;i<n;i++){
        printf("%d ",A[i]);
    }

    bubbleSortInput(A,n);

    printf("\n");

    printf("Array After Sorting: ");
    for (int i =0;i<n;i++){
        printf("%d ",A[i]);
    }
}