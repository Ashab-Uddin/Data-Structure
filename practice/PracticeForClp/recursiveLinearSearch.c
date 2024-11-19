int recursiveLinearSearch(int A[],int n, int value){
    if(n == 0){
        return -1;
    }
    if(A[n-1] == value){
        return 1;
    }
    return recursiveLinearSearch(A,n-1,value);
}

#include<stdio.h>
int main(){
    int n,value,result;
    printf("Enter the size of an array: ");
    scanf("%d",&n);

    int A[n];

    printf("Enter the element of an array: ");
    for(int i = 0; i<n; i++){
        scanf("%d",&A[i]);
    }

    printf("Enter the search Value: ");
    scanf("%d",&value);

    result = recursiveLinearSearch(A,n,value);

    if(result == 1){
        printf("Element %d found in the array.\n", value);
    }
    else{
        printf("Element %d not found in the array.\n", value);
    }

    return 0;
}