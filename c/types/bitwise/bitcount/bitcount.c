#include <stdio.h>

/* bitcount: count 1 bits in x */
int bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; x &= (x-1)) { b++; }
    return b;
}

int main(void) {
    for(int i = 0; i < 10; ++i) {
        printf("Int %d has %d bits\n", i, bitcount(i));
    }
    return 0;
}
