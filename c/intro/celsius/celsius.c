#include <stdio.h>
 /* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300 */
 main() {
    float fahr, celsius;
    int lower, upper, step;
    
    lower = 0; /* lower limit of temperature scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    fahr = lower;
    printf("Fahrenheits to Celsius\n");
    printf("%3s\t%3s", "F", "C");
    printf("\n___________________\n");
    while (fahr <= upper) {
        celsius = 5.0 * (fahr-32) / 9.0;
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
 }
