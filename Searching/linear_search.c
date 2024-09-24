#include <stdio.h>

int linearSearch(int A[], int value, int i, int size) {
    if (i >= size) {
        return -1;
    }
    else if (A[i] == value) {
        return i; 
    }
    return linearSearch(A, value, i + 1, size);
}

int main() {
    int A[] = {3,5,6,80,23,53,2,56,12,45};
    int value;
    int size ;
        size = sizeof(A) / sizeof(A[0]);
    
    printf("\nEnter the number to search: ");
    scanf(" %d", &value);

    int i=0;
    int result = linearSearch(A, value, i, size);
    
    if (result == -1) {
        printf("Value '%d' is not found in the ar.\n", value);
    } else {
        printf("Value '%d' is found at index %d.\n", value, result);
    }
    return 0;
}
