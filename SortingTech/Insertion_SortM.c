#include <stdio.h>

void insertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];      
        int j = i - 1;

      
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;     
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

   
    insertionSort(A, n);

  
    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
