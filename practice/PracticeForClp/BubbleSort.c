#include<stdio.h>
void bubbleSort(int A[],int n){
    int temp,flag;
    for(int i = 0;i<n-1; i++){
        flag = 0;
        for(int j = 0; j<n-1-i; j++){
            if(A[j]>A[j+1]){
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
    int A[] = {9,2,4,1,5,4,8,2,1,6};
    int n = sizeof(A)/sizeof(A[0]);

    printf("Before Sort: ");
    for(int i = 0;i<n;i++){
        printf("%d ",A[i]);
    }

    printf("\n");

    bubbleSort(A,n);

    printf("After Sort: ");
    for(int i = 0; i<n; i++){
        printf("%d ",A[i]);
    }
}