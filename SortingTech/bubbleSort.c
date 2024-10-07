#include<stdio.h>
void bubbleSort(int A[],int length){
    int flag,temp;
    for(int i=0;i<length-1;i++){
        flag = 0;
        for (int j=0;j<length-1-i; j++)
        {
            if(A[j] > A[j+1])
            {
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
    int item,flag;
    int A[] ={15,16,6,8,5};
    int length = sizeof (A) / sizeof(A[0]);

    printf("Array before sorting: ");
    for(int i =0;i<length;i++){
        printf("%d  ",A[i]);
    }
    printf("\n");

    bubbleSort(A,length);

    printf("Array after sorting:  ");
    for(int i =0;i<length;i++){
        printf("%d  ",A[i]);
    }
    
    return 0;
}