#include<stdio.h>
int binarySearch(int A[],int searchValude,int length){
    int l=0,r=length-1;
    while(l<=r){
        int mid =(l+r)/2;
        if(searchValude == A[mid]){
            return mid;
        }
        else if(searchValude<A[mid]){
            r =mid -1;
        }
        else{
            l = mid+1;
        }
    }
    return -1;
}
int main(){
    int A[] = {5,9,17,23,25,46,59,63,71,89};
    int length = sizeof(A)/sizeof(A[0]);
    int searchValude;

    printf("Enter the searching Value: ");
    scanf("%d",&searchValude);

    int result =binarySearch(A,searchValude,length);

    if(result>=0){
        printf("Searching Value is found at index: %d",result);
    }
    else{
        printf("Searching Value is not found");
    }
}