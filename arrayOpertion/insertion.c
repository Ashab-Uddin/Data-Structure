#include<stdio.h>
int main(){
    int a[50],size,num,index,i;

    printf("Enter the size of an array: ");
    scanf("%d",&size);

    printf("Enter the %d elements of an array: ",size);
    for (int i=0; i<size; i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the number you want to insert: ");
    scanf("%d",&num);

    printf("Enter the index: ");
    scanf("%d",&index);

    
    for (int i=size-1; i>=index; i--){
        a[i+1] = a[i];
    }
    a[index] = num;
    size++;
    printf("Here is the Final array element: ");
    for ( i = 0; i<size; i++){
        printf("%d ",a[i]);
    }
    

    return 0;
}