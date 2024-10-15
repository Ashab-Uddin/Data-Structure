#include<stdio.h>
int main(){
    int A[] = {2,4,24,54,65,76,32,62,34,4,6,27,75};
    int searchValude;
    int found =0;

    int length = sizeof(A)/sizeof(A[0]);

    printf("Enter the Searching Value: ");
    scanf("%d",&searchValude);

    for(int i =0;i<length;i++){
        if(A[i] == searchValude){
            printf("Searching Value is found at index: %d",i);
            found =1;
            break;
        }
        
    }
    if(found==0){
            printf("Searching Value is not found");
        }
    return 0;
}