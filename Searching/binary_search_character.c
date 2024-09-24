#include <stdio.h>

int binarySearchCharacter(char A[], char value, int L, int R) {
    
    if (L > R) {
        return -1;
    }

    int middle = L + (R - L) / 2;
    if (A[middle] == value) {
        return middle; 
    }
    else if (A[middle] > value) {
        return binarySearchCharacter(A, value, L, middle - 1);
    }
    else{
    return binarySearchCharacter(A, value, middle + 1, R);
    }
}

int main() {
    
    char A[] = {'a', 'b', 'e', 'i', 'm', 'p', 'x', 'z'};
    char value;
    
    int size ;
        size = sizeof(A) / sizeof(A[0]);
    
    printf("\nEnter the character to search: ");
    scanf("%c", &value);
    int i=0;
    int result = binarySearchCharacter(A, value, i, size - 1);
    
    if (result == -1) {
        printf("Character '%c' is not found in the array.\n", value);
    } else {
        printf("Character '%c' is found at index %d.\n", value, result);
    }
    return 0;
}
