#include <stdio.h>

int  linearSearchCharacter(char A[], char value, int i, int size) {
    if (i >= size) {
        return -1; 
    }
    else if (A[i] == value) {
        return i; 
    }
    return  linearSearchCharacter(A, value, i + 1, size); 
}

int main() {
    char A[] = {'a', 's', 'h', 'b', 'd', 'u', 'i', 'n'};
    char value;
    int size = sizeof(A) / sizeof(A[0]);

    printf("\nEnter the character to search: ");
    scanf(" %c", &value);

    int result = linearSearchCharacter(A, value, 0, size);

    if (result == -1) {
        printf("Character '%c' is not found in the array.\n", value);
    } else {
        printf("Character '%c' is found at index %d.\n", value, result);
    }
    
    return 0;
}
