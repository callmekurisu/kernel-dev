#include <stdio.h>
#define ALLOCSIZE 100
#define ERROR_CODE -1
#define EXPECTED_ARGS 2
#define ZERO 0
#define ONE 1
#define FORMAT "%s\n"
#define NULL_BYTE '\0'
#define USAGE "Usage: pointer.c 'string to reverse'\n"
#define BUFFER_OVERFLOW "Buffer overflow error\n"
#define BS '\b'
/* reverse word input */
void reverse(char *i, char *o, int l); // declare reversing function
char *alloc(int n); // declare memory allocation function
int main(int c, char **args) { // entry point
    int index = ZERO; // initialize index for string length
    if(c != EXPECTED_ARGS) { // check for bad input
        printf(USAGE); // display usage message
        return ERROR_CODE; // exit with error code
    }
    while(args[ONE][index] != NULL_BYTE) { ++index; } // get word length
    char * a = alloc(index);
    if(a == ZERO) { // allocate memory check
        printf(BUFFER_OVERFLOW); // display error message
        return ERROR_CODE; // return error code
    }
    reverse(args[ONE], a, index); // call recursive reverse function
    printf(FORMAT, a); // display result
}
/* recursively reverse a string with pointers */
void reverse(char *i, char *o, int l) {
    int inc = ZERO; // initialize pointer incrementing
    if(*i != BS && *i != NULL_BYTE) { // check for backspace and end of input
        *(o+(--l-(inc++))) = *i; ++i; // pointer magic
        reverse(i, o, l); // functions calls itself until reaching end of input
    }
}
/* return pointer to n characters */
char *alloc(int n) {
    static char allocbuf[ALLOCSIZE]; /* storage for alloc */
    static char *allocp = allocbuf; /* next free position */
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else
        /* not enough room */
        return ZERO;
}
