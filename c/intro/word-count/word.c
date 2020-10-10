#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define NL '\n'
#define TAB '\t'
#define BLANK ' '
/* count lines, words, and characters in input */
main() {
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        _Bool terminator = c == BLANK || c == NL || c == TAB;
        ++nc;
        putchar(c);
        if (c == NL) {
            ++nl;
            printf("Lines: %d | Words: %d | Characters: %d\n", nl, nw, nc);
        }
        if (terminator) {
            state = OUT;
            putchar('\n');
        }
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
}
