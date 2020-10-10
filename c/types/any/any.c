#include <stdio.h>
#define ZERO 0
#define ONE 1
#define TWO 2
#define NOT_FOUND -1
#define EXPECTED_ARGS 3
#define NULL_BYTE '\0'
#define BUFFER 20
#define ARG_ERROR "Expected 2 arguments got 1.\n"
#define USAGE "Usage: %s string1 string2\n"

int any(char s1[], char s2[]); // declare any method
int validate(int count, char ** args); // declare error handling

int main(int count, char ** args) { // entry point
    if(validate(count, args) != ZERO) { return TWO; } // handle errors
    int result = any(args[ONE],args[TWO]); // run any
    printf("Match at index: %d\n", result); // display result
    return ZERO; // clean exit
}

int any(char s1[], char s2[]) { /* any: find location in s1 first match from s2 */
    int i, k = ZERO;
    int location = NOT_FOUND;
    for (i = ZERO; s1[i] != NULL_BYTE; i++) {
        for(int j = ZERO; s2[j] != NULL_BYTE; j++) {
            if(s1[i] == s2[j]) { location = i; break; } // set element on non-matching
        }
        if(location > NOT_FOUND) { break; }
    }
    return location;
}

int validate(int count, char ** args) {
    if(count != EXPECTED_ARGS) { // must get 3 args
        printf(ARG_ERROR);
        printf(USAGE, args[ZERO]);
        return TWO;
    }
    return ZERO;
}
