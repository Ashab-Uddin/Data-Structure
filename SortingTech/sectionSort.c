#include<stdio.h>
void selectionSort(int A[], int length){
    int min,temp;
    for(int i = 0;i<length-1;i++){
        min = i;
        for(int j = i+1; j<length;j++){
            if(A[j] < A[min]){
                min = j;
            }
        }
    if(min != i){
        // swap(A[i],A[min]);
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
    }
}


int main(){
    int A[] = {7,4,10,8,3,1};
    int length = sizeof(A)/sizeof(A[0]);

    printf("Array Before Sorting: ");
    for(int i=0;i<length;i++){
        printf("%d ",A[i]);
    }


    selectionSort(A,length);

    printf("\n");

    printf("Array After Sorting: ");
    for (int i =0;i<length;i++){
        printf("%d ",A[i]);
    }

    return 0;
}