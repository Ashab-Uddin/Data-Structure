#include<stdio.h>
void bubbleSortdec(int A[],int length){
    int flag ,temp;
    for(int i =0;i<length-1;i++){
        flag = 0;
        for(int j = 0;j<length-1-i;j++){
            if(A[j]<A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                flag =1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}
int main(){
    int A[] = {3,54,65,86,34,2,56,23,1,66,35};
    int length = sizeof(A)/sizeof(A[0]);

    printf("Array Before Sorting: ");
    for (int i =0;i<length;i++){
        printf("%d ",A[i]);
    }

    bubbleSortdec(A,length);

    printf("\n");

    printf("Array After Sorting: ");
    for(int i=0;i<length;i++){
        printf("%d ",A[i]);
    }

    return 0;
}