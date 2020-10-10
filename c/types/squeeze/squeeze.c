#include <stdio.h>
#define ZERO 0
#define ONE 1
#define TWO 2
#define EXPECTED_ARGS 3
#define NULL_BYTE '\0'
#define BUFFER 20
#define ARG_ERROR "Expected 2 arguments got 1.\n"
#define USAGE "Usage: %s string1 string2\n"

void squeeze(char s1[], char s2[]); // declare squeeze method
int validate(int count, char ** args); // declare error handling

int main(int count, char ** args) { // entry point
    if(validate(count, args) != ZERO) { return TWO; } // handle errors
    squeeze(args[ONE],args[TWO]); // run squeezing
    printf("Result : %s\n", args[ONE]); // display result
    return ZERO; // clean exit
}

void squeeze(char s1[], char s2[]) { /* squeeze: delete all s1 matching from s2 */
    int k = ZERO; 
    for (int i = ZERO; s1[i] != NULL_BYTE; i++) {
        for(int j = ZERO; s2[j] != NULL_BYTE; j++) {
            if(s1[i] != s2[j]) { s1[k] = s1[i]; } // set element on non-matching
            else { s1[k] = NULL_BYTE; break; } // set element to null on match
        }
    if(s1[k] != NULL_BYTE) { ++k; } // if no matching iterate
    }
    s1[k] = NULL_BYTE; // remove excess
}

int validate(int count, char ** args) {
    if(count != EXPECTED_ARGS) { // must get 3 args
        printf(ARG_ERROR);
        printf(USAGE, args[ZERO]);
        return TWO;
    }
    return ZERO;
}
