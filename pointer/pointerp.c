#include<stdio.h>

void swap(int* n1, int* n2) {
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main() {
    int num1 = 20, num2 = 30;

    printf("Before Swap\n");
    printf("Num1: %d\nNum2: %d\n", num1, num2);

    // Pass the addresses of num1 and num2
    swap(&num1, &num2);

    printf("After Swap\n");
    printf("Num1: %d\nNum2: %d\n", num1, num2);

    return 0;
}
