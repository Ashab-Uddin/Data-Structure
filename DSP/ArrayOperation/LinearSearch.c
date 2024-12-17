#include<stdio.h>
int main(){
    int item,found = 0;
    int A[] = {23,54,13,54,3,13,54,1,5,2,61,64,13,23};
    int n = sizeof(A)/sizeof(A[0]);

    printf("The Array\n");
    for(int i = 0;i<n;i++){
        printf("%d ",A[i]);
    }

    printf("\nEnter Your Searching Item: ");
    scanf("%d",&item);

    for(int i =0;i<n;i++){
        if(A[i] == item){
            printf("Item is found at index %d",i);
            found = -1;
            break;
        }
    }
    if(found ==  0){
        printf("Item is not found");
    }

    return 0;
}