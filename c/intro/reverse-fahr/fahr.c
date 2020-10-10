#include <stdio.h>
#define LOWER 0
#define UPPER 50
#define STEP 2.5
int fahrConv(float c);
 /* print Celsius-Fahrenheit table
 for fahr = 0, 2.5, ..., 50 */
 main() {
    float celsius;
    printf("Celsius to Fahrenheit\n");
    printf("%3s\t%3s", "C", "F");
    printf("\n___________________\n");
    for (celsius = UPPER; celsius >= LOWER; celsius = celsius - STEP) {
        printf("%3.0f\t%6.d\n", celsius, fahrConv(celsius));
    }
 }
 /* Function to return Fahrenheit*/
 int fahrConv(float celsius) { return (celsius * (9.0 / 5.0)) + 32; }
