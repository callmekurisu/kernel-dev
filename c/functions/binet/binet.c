#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define PHI 1.618
#define ERROR_CODE -1
#define EXPECTED_ARGS 2
#define ZERO 0
#define ONE 1
#define FORMAT "F(%d) = %lu\n"
#define USAGE "Binet's Algorithm\nUsage: binet n \nOutput: F(n)\n"
/* Binet's algo in C*/
int main(int c, char **argv) {
    float psi = ONE - PHI; // define psi
    char *ao = argv[ONE]; // set input
    int n = ao != NULL ? atoi(ao) : ZERO; // set n
    _Bool err = c != EXPECTED_ARGS || n == ZERO; // define error
    if(!err) { printf(FORMAT, n, (unsigned long) ceil((pow(PHI, n) - pow(psi, n)) / (PHI - psi))); } // display result
    else { printf(USAGE); } // display usage message 
    return err ? EXIT_FAILURE : EXIT_SUCCESS; // return exit status
}
