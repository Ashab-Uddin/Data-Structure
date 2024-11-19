#include<stdio.h>


int binarySearchCharacter(char A[], char value, int l, int r) {
    if (l > r) {
        return -1; 
    }

    int mid = (l + r) / 2; 

    if (A[mid] == value) { 
        return mid; 
    } else if (A[mid] > value) { 
    
        return binarySearchCharacter(A, value, l, mid - 1);
    } else { 
        
        return binarySearchCharacter(A, value, mid + 1, r);
    }
}

int main() {
    char A[] = {'a', 'b', 'd', 'd', 'h', 'i', 's', 'u'}; 
    char value;
    int result;
    int size = sizeof(A) / sizeof(A[0]);

    printf("Enter the finding value: ");
    scanf(" %c", &value); 

    result = binarySearchCharacter(A, value, 0, size - 1);

    if (result == -1) {
        printf("%c is not found in the array\n", value);
    } else {
        printf("%c is found at index %d\n", value, result);
    }

    return 0;
}
