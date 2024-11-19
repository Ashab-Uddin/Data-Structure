#include <stdio.h>

int main() {
    int i, j, n, count = 0;

    // Input the size of the array
    printf("Enter the size of an array: ");
    scanf("%d", &n);

    int A[n];

    // Input the elements of the array
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Count duplicate elements
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (A[i] == A[j]) {
                count++;
                break; // Move to the next element after finding a duplicate
            }
        }
    }

    // Output the result
    printf("Total duplicate elements: %d\n", count);

    return 0;
}
