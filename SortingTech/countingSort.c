#include<stdio.h>

// Counting Sort function
void countSort(int A[], int n, int max){
    int count[max + 1];  // Create the count array with size max+1
    int B[n];  // Create the output array

    // Initialize the count array to 0
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Count the occurrences of each element in the input array
    for (int i = 0; i < n; i++) {
        count[A[i]]++;
    }

    // Modify the count array to store the actual positions of elements
    for (int i = 1; i <= max; i++) {
        count[i] = count[i] + count[i - 1];
    }

    // Build the output array by placing the elements in their correct positions
    for (int i = n - 1; i >= 0; i--) {
        B[--count[A[i]]] = A[i];
    }

    // Copy the sorted elements back into the original array
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}

int main(){
    int A[] = {2, 1, 1, 0, 2, 5, 4, 0, 2, 8, 7, 7, 9, 2, 0, 1, 9};
    int n = sizeof(A) / sizeof(A[0]);
    int max = A[0];

    // Find the maximum element in the array
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }

    // Print the array before sorting
    printf("Before Sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    // Perform Counting Sort
    countSort(A, n, max);

    // Print the array after sorting
    printf("\nAfter Sorting:  ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
