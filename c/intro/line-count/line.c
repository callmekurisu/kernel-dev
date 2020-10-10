#include <stdio.h>
/* count lines in input */
#define BLANK ' '
main() {
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t' || c == '\b') { putchar('\\'); }
        putchar(c);
    }
}
