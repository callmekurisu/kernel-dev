#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define NL '\n'
#define TAB '\t'
#define BLANK ' '
#define INIT 10 /* count word length less than 10*/
/* count lines, words, and characters in input */
main() {
    int c, nl, nw, nc, state;
    int lword[INIT];
    state = OUT;
    nl = nw = nc = 0;
    // initialize array
    for (int i = 0; i < INIT; ++i)
            lword[i] = 0;
    while ((c = getchar()) != EOF) {
        _Bool terminator = c == BLANK || c == NL || c == TAB;
        ++nc;
        if (terminator) { 
            state = OUT; 
            ++lword[nc-1]; // increase count based on world length and reset
            nc = 0;
        }
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("\nLines: %d | Words: %d\n", nl, nw);
    printf("Word Count Histogram:\n");
    for(int w = 0; w <= INIT; w++) {
        printf("\n%d: ", w);
        for(int a = 0; a < lword[w]; a++ ){ printf("*"); }
    }
    printf("\n");
}
