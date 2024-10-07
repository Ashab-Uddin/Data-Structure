#include<stdio.h>
void insertionSort(int A[],int length){
    int temp,j,i;
    for(int i =1;i<length;i++){
        temp =A[i];
        j = i-1;
        
        while(j>=0 && A[j]>temp){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
        }

}
int main(){
    int A[] = {5,4,10,1,6,2};
    int length = sizeof(A)/sizeof(A[0]);

    printf("Array Befor Sorting: ");
    for(int i =0;i<length;i++){
        printf("%d ",A[i]);
    }

    insertionSort(A,length);

    printf("\n");

    printf("Array After Sorting: ");
    for(int i=0;i<length;i++){
        printf("%d ",A[i]);
    }

    return 0;

}