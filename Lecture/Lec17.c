#include <stdio.h>

void ToH (int n, char from_rod, char to_rod, char via_rod) {
    if (n == 1) {
        printf ("%d from: %c, to: %c, via: %c\n", n, from_rod, to_rod, via_rod);
        return;
    }
    
    ToH (n-1, from_rod, via_rod, to_rod);
    printf ("%d from: %c, to: %c, via: %c\n", n, from_rod, to_rod, via_rod);
    ToH (n-1, via_rod, to_rod, from_rod);
}

int main () {
    ToH (22, 'A', 'B', 'C');
    return 0;
}