#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER 1000
#define NEEDLE 777
#define NO_MATCH -1
#define HIGH 999

int binsearch(int x , int v[], int n);
int main(void) {
    int i, n;
    time_t t;
    int a [BUFFER];

    for(int i = 0; i < BUFFER; ++i) { a[i] = i; }
    int m = binsearch(NEEDLE, a, HIGH);
    if(m == NO_MATCH){ printf("No match found\n"); }
    else { printf("Match value = %d\n", m); }
}
/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid + 1;
        else if (x > v[mid])
            low = mid +1;
        else 
            return mid;
    }
    /*
     Execution time with second loop
     real    0m0.004s
     user    0m0.001s    
     sys     0m0.004s

    while(mid <= n) {
        if (x > v[mid])
            mid++;
        else 
            return mid;
    }
        */
    return NO_MATCH; /* no match */
}
