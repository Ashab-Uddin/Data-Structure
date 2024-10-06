#include<stdio.h>
int main(){
    int i,item,lb,ub,found = 0;
    int A[20];

    printf("Enter the ub of an array: ");
    scanf("%d",&lb);
    printf("Enter the ub of an array: ");
    scanf("%d",&ub);

    printf("Enter the %d to %d element: ",lb,ub);
    for(i =lb;i<=ub;i++){
        scanf("%d",&A[i]);
    }
    printf("\n");

    printf("The Array: ");
    for(i = lb;i<=ub;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    printf("Enter your finding number: ");
    scanf("%d",&item);

    for (i=lb;i<=ub;i++){
        if(A[i] == item){
            printf("%d is found in index: %d",item,i);
            found = 1;
            break;
        }
    }
    printf("\n");
    if(found == 0){
        printf("%d is not found",item);
    }
    return 0;
}