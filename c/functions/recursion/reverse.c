#include <stdio.h>
#define REVERSE_BUFFER 100
#define ERROR_CODE -1
#define EXPECTED_ARGS 2
#define ZERO 0
#define ONE 1
#define FORMAT "%s\n"
#define NULL_BYTE '\0'
#define BAD_BOY "Bad input detected!\n"
#define BS '\b'
/* reverse word input */
int reverse(char i[], char o[], int l, int j); // declare reversing function
int main(int c, char ** args) { // entry point
    int index = ZERO; // initialize index for string length
    char r[REVERSE_BUFFER]; // initialize buffer for reversed string
    if(c != EXPECTED_ARGS) { // check for bad input
        printf(BAD_BOY); // display error message
        return ERROR_CODE; // exit with error code
    }
    while(args[ONE][index] != NULL_BYTE) { ++index; } // get word length
    if(index >= REVERSE_BUFFER) {  // handle buffer overflow
        printf(BAD_BOY); // display error message
        return ERROR_CODE; // exit with error code
    }
    reverse(args[ONE], r, index, ZERO); // call recursive reverse function
    printf(FORMAT, r); // display result
}
/* recursively reverse a word */
int reverse(char i[], char o[], int l, int j) {
    if(i[j] == NULL_BYTE) { return ZERO; } // exit with success on null byte
    if(i[j] != BS) { o[--l] = i[j]; } // handle back space
    reverse(i, o, l, ++j); // functions calls itself until reaching end of input
    return ERROR_CODE; // edge case here
}
