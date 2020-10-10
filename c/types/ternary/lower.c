#include <stdio.h>

/* Ternary Edition of lower: convert c to lower case; ASCII only */
int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

int main(void) {
    for(int i = 'A'; i <= 'Z'; i++) {
        printf("lower(%c) => %c\n", (char) i, (char) lower(i));
    }
}
