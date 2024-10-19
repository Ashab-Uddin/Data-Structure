#include<stdio.h>
int sum(int *arr,int size){
    int sum = 0;
    for(int i = 0;i<size;i++){
        sum = sum+ *(arr+i);
    }
    return sum;
}
int main(){
    int arr[] = {3,5,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    int result = sum(arr,size);

    printf("Sum of the array is: %d",result);

    return 0;
}