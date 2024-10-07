#include<stdio.h>

int main(){
    int A[] = {9, 5, 2, 6, 0, 1, 4};
    int index;
    int size = sizeof(A) / sizeof(A[0]);

    printf("Before Delete: ");
    for(int i = 0; i < size; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("Enter the index to delete: ");
    scanf("%d", &index);
    
    // Check if the index is out of bounds
    if (index < 0 || index >= size){
        printf("Invalid Input\n");
    } else {
        // Shift elements to the left from the given index
        for (int i = index; i < size - 1; i++){
            A[i] = A[i + 1];
        }
        size -= 1;  // Reduce the size by 1

        // Print the array after deletion
        printf("After Delete: ");
        for (int i = 0; i < size; i++){
            printf("%d ", A[i]);
        }
        printf("\n");
    }

    return 0;
}
