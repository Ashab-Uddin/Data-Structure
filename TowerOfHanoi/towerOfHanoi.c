#include <stdio.h>

void towerOfHanoi(int N, char BEG, char AUX, char END) {
    if (N == 0) return;
    towerOfHanoi(N - 1, BEG, END, AUX);
    printf("Move disk %d from %c to %c\n", N, BEG, END);  // Corrected here
    towerOfHanoi(N - 1, AUX, BEG, END);
}

int main() {
    int N;
    printf("Enter the number of disks: ");
    scanf("%d", &N);
    printf("Tower of Hanoi solution for %d disks:\n", N);
    towerOfHanoi(N, 'A', 'B', 'C');  // Correct order for BEG, AUX, END
    return 0;
}
