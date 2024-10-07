#include <stdio.h>

int main() {
    int A[100];
    int n, key;
    int swapped;

    printf("Enter the size of an array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        swapped = 0;  
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                key = A[j];
                A[j] = A[j + 1];
                A[j + 1] = key;
                swapped = 1;  
            }
        }
        if (!swapped) {
            break;  
        }
    }

    printf("The Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
