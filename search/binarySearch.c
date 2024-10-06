#include<stdio.h>
int binarySearch(int A[], int length,int item){
    int l=0; int r=length-1;
    
    while(l<=r){
        int mid = (l + r) / 2;
        if(item == A[mid]){
            return mid;
        }
        else if(item < A[mid]){
            r = mid -1;

        }
        else{
            l= mid+1;
        }
    }
    return -1;
}
int main(){
    int item;
    int A[] ={5, 9, 17, 23, 25, 45, 59, 63, 71, 89};

    int length = sizeof(A) / sizeof(A[0]);

    printf("Array is: ");
    for(int i=0;i<length;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    printf("Enter the searching item: ");
    scanf("%d",&item);

    int result =binarySearch(A,length,item);

    if(result>= 0){
        printf("Item is found at Index: %d",result);
    }
    else{
        printf("Item is not found");
    }

}