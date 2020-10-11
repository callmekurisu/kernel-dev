#include <stdio.h>
#include <ctype.h>
#define ALLOCSIZE 100
#define ERROR_CODE -1
#define EXPECTED_ARGS 2
#define ZERO 0
#define ONE 1
#define MATCH 3
#define FORMAT "%s\n"
#define NULL_BYTE '\0'
#define USAGE "Usage: gcc -o <lower or upper> lowOrUp.c\n ./lower or ./upper 'string to modify'\n"
#define BUFFER_OVERFLOW "Buffer overflow error\n"
#define BS '\b'
#define LOWER "./lower"
#define UPPER "./upper"
/* lowercase or uppercase word input */
void lowOrUp(char *i, char *o, int f); // declare lowercase function
int strindex(char *s, char *t); // delcare string index function
char *alloc(int n); // declare memory allocation function
int processInput(char *az, char *ao, char *mem); // declare processInput function
int main(int c, char **args) { // entry point
    int index = ZERO; // initialize index for string length
    char *az = args[ZERO];
    char *ao = args[ONE];
    while(ao[index] != NULL_BYTE) { ++index; } // get word length
    char * a = alloc(index);
    if(c != EXPECTED_ARGS || processInput(az, ao, a) == ERROR_CODE) { // check for bad input
        printf(USAGE); // display usage message
        return ERROR_CODE; // exit with error code
    }
    printf(FORMAT, a); // display result
}
/* recursively lowercase a string with pointers */
void lowOrUp(char *i, char *o, int f) {
    if(*i != BS && *i != NULL_BYTE) { // check for backspace and end of input
        if(f == ZERO) { *o++ = tolower(*i); ++i; } // pointer magic
        if(f == ONE) { *o++ = toupper(*i); ++i; } // pointer magic
        lowOrUp(i, o, f); // functions calls itself until reaching end of input
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
/* strindex: return index of t in s, -1 if none */
// int strindex(char *s, char *t) {
//     int i, j, k;
//     for (i=ZERO; s[i] != '\0'; i++) {
//         for (j=i, k=ZERO; t[k]!='\0' && s[j]==t[k]; j++, k++)
//             ;
//         if (k > ZERO && t[k] == '\0')
//         return i;
//     }
//     return ERROR_CODE;
// }
int strindex(char *s, char *t) {
    int inc = ERROR_CODE;
    while(*s++ == *t++) { if(*t != NULL_BYTE) { ++inc; } }
    if(inc < MATCH) { inc = ERROR_CODE; }
    return inc;
}
/* process input */
int processInput(char *az, char *ao, char *mem) {
    if(mem == ZERO) { // allocate memory check
        printf(BUFFER_OVERFLOW); // display error message
        return ERROR_CODE; // return error code
    }
    /* modify program behavior on binary filename */
    if(strindex(LOWER, az) != ERROR_CODE) {
        lowOrUp(ao, mem, ZERO); // call recursive lower function
    }
    /* modify program behavior on binary filename */
    else if(strindex(UPPER, az) != ERROR_CODE) {
        lowOrUp(ao, mem, ONE); // call recursive lower function
    } else {
        return ERROR_CODE;
    }
    return ONE;
}
