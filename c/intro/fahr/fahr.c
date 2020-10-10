#include <stdio.h>
 /* print Celsius-Fahrenheit table
 for fahr = 0, 5, ..., 30 */
 main() {
    float fahr, celsius;
    int lower, upper, step;
    
    lower = 0; /* lower limit of temperature scale */
    upper = 50; /* upper limit */
    step = 5; /* step size */
    celsius = lower;
    printf("Celsius to Fahrenheit\n");
    printf("%3s\t%3s", "C", "F");
    printf("\n___________________\n");
    while (celsius <= upper) {
        fahr = (celsius * (9.0 / 5.0)) + 32;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
 }
