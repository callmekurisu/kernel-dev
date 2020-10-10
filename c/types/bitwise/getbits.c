#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main () {
    unsigned a = 8; // 1000
    int b = 4;
    int c = 3;
    int y = 1;
    printf("Result: %d\n", getbits(a, b, c));
    return 0;
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}
