#include <stdio.h>
#include <stdlib.h>
#define ZERO 0
#define ONE 1
#define RESULT "%d! = %d\n"
#define NO_INPUT "Error. No input.\n"
// recursive ternary for returning factorial values
int f(int n) { return n == ZERO ? ONE : n * f(n - ONE); }
int main(int c, char ** a) {
    if(a[ONE] == NULL || c < ONE) { 
        printf(NO_INPUT); 
        return ONE; 
    }
    int n = atoi(a[ONE]);
    printf(RESULT, n, f(n));
}
