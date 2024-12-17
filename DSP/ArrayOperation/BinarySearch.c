#include<stdio.h>
int BinarySearch(int A[],int n,int data){
    int r,l,mid;
    l =0;r=n-1;
    while(l<r){
        mid = (l+r)/2;

        if(data == A[mid]){
            return mid;
        }
        else if(data<A[mid]){
            r = mid -1;
        }
        else{
            l = mid+1;
        }
    }
    return -1;
}
int main(){
    int data;
    int A[] = {2,4,5,6,7,8,9,10,22,24,25,26,27,30};
    int n = sizeof(A)/sizeof(A[0]);
    printf("Array is\n");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    printf("\nEnter the Searching data: ");
    scanf("%d",&data);
    int result = BinarySearch(A,n,data);

    if(result >0){
        printf("Item is found at index %d",result);
    }
    else{
        printf("Item is not found");
    }

    return 0;
}