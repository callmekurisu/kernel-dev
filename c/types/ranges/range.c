#include <limits.h>
#include <stdio.h>
#define ZERO 0
int main() {
    printf("\t%20s\t%20s\n", "min", "max");
    printf("%6s: %20d\t%20d\n", "char", CHAR_MIN, CHAR_MAX);
    printf("%6s: %20d\t%20d\n", "uchar", ZERO, UCHAR_MAX);
    
    printf("%6s: %20d\t%20d\n", "int", INT_MIN, INT_MAX);
    printf("%6s: %20d\t%20u\n", "uint", ZERO, UINT_MAX);
    
    printf("%6s: %20d\t%20d\n", "short", SHRT_MIN, SHRT_MAX);
    printf("%6s: %20d\t%20u\n", "ushort", ZERO, USHRT_MAX);
    
    printf("%6s: %20ld\t%20ld\n", "long", LONG_MIN, LONG_MAX);
    printf("%6s: %20d\t%20lu\n", "ulong", ZERO, ULONG_MAX);
    
    return ZERO;
}
