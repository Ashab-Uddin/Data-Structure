#include <stdio.h>


int linearSearchCharacter(char A[], char value, int size, int i) {
    if (i >= size) {
        return -1; 
    }
    if (A[i] == value) {
        return i; 
    }
    return linearSearchCharacter(A, value, size, i + 1); 
}

int main() {
    char A[] = {'a', 's', 'h', 'b', 'u', 'd', 'd', 'i', 'n'};
    char value;
    int size = sizeof(A) / sizeof(A[0]);
    int i = 0, result;


    printf("Enter the searching character: ");
    scanf(" %c", &value);


    result = linearSearchCharacter(A, value, size, i);


    if (result == -1) {
        printf("Character '%c' is not found in the array.\n", value);
    } else {
        printf("Character '%c' is found at index %d.\n", value, result);
    }

    return 0;
}
