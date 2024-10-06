#include<stdio.h>
void bubbleSort(int A[], int length)
{
    int flag ,temp;
for (int i =0;i<length-1;i++){
    flag =0;
    for(int j=0;j<length-1-i;j++){
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
    int A[] = {42,35,77,12,101,5};

    int length = sizeof(A) / sizeof(A[0]);

    printf("Array Befor Sorting: ");
    for(int i =0;i<length;i++){
        printf("%d ",A[i]);
    }
    

    bubbleSort(A,length);

printf("\n");
    printf("Array After Sorting: ");
    for(int i = 0;i<length;i++){
        printf("%d ",A[i]);
    }
    
    return 0;
}