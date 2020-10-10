#include <stdio.h>
/* maximum string size */
#define REVERSE_BUFFER 1000
#define ZERO 0
#define FORMAT "\n%s\n"
#define NEWLINE '\n'
void reverse(char in[], char out[], int length);
int main(int count, char ** args) {
    int index = 0;
    char r[REVERSE_BUFFER];
    while(args[1][index] != '0') {
        index++;
    }
    reverse(args[1], r, index);
    printf(FORMAT, r);
}
void reverse(char in[], char out[], int length) {
    int j = ZERO;
    for(int i = length; i > ZERO; --i) {
        out[i] = in[j];
        ++j;
    }
}
