#include<stdio.h>

void bubbleSort(int A[], int length) {
    int flag, temp;
    for (int i = 0; i < length - 1; i++) {
        flag = 0;
        for (int j = 0; j < length - 1 - i; j++) {  
            if (A[j] > A[j + 1]) {  
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

int main() {
    int A[] = {16, 14, 5, 6, 8};
    int length = sizeof(A) / sizeof(A[0]);

    printf("Before Sort: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    bubbleSort(A, length);

    printf("After Sort: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
