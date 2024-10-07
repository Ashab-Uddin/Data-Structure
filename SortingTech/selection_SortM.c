#include <stdio.h>

void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
       
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[minIndex]) {
                minIndex = j;  
            }
        }
        
        
        if (minIndex != i) {
            int temp = A[i];
            A[i] = A[minIndex];
            A[minIndex] = temp;
        }
    }
}

int main() {
    int A[100], n;

   
    printf("Enter the size of the array: ");
    scanf("%d", &n);

  
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

   
    selectionSort(A, n);

    
    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
