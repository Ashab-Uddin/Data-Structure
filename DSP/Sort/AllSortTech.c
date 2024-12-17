#include<stdio.h>
int BubbleSort(int A[],int n){
    int temp;
    for(int i = 0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}
int InsertionSort(int A[],int n){
int temp;
for(int i = 1;i<n;i++){
    temp = A[i];
    int j = i-1;
    while(j>=0 && A[j]>temp){
        A[j+1] = A[j];
        j--;
    }
    A[j+1] = temp;
}
}
int SelectionSort(int A[],int n){
    int min,temp,i;
    for(int i =0;i<n-1;i++){
        int min = i;
    for(int j = i+1; j<n; j++){
        if(A[j]<A[min]){
            min = j;
        }
    }
    if(min != i){
        temp = A[min];
        A[min] = A[i];
        A[i] = temp;
    }
    }
}
int CountingSort(int A[],int n){
    printf("Under Constraction of Counting");
}
int display(int A[],int n){
    printf("After Sorting\n");
    for(int i = 0;i<n;i++){
        printf("%d ",A[i]);
    }
}

int main(){
    int choice;
    int A[] = {23,54,13,54,3,13,54,1,5,2,61,64,13,23};
    int n = sizeof(A)/sizeof(A[0]);
    printf("Before  Sorting\n");
    for(int i = 0;i<n;i++){
        printf("%d ",A[i]);
    }
    do{
        printf("\nSort Menu");
        printf("\n1. Bubble Sort");
        printf("\n2. Insertion Sort");
        printf("\n3. Selection Sort");
        printf("\n4. Counting Sort");
        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                BubbleSort(A,n);
                display(A,n);
                break;
            case 2:
                InsertionSort(A,n);
                display(A,n);
                break;
            case 3:
                SelectionSort(A,n);
                display(A,n);
                break;
            case 4:
                CountingSort(A,n);
                break;
            default:
            printf("Invalid Choice! Please Try again Later");
        }
        
    }while(choice != 0);
    
}