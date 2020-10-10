#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define HEX_BUFFER 10
#define ZERO 0
#define LITERAL_ZERO '0'
#define ONE 1
#define TWO 2
#define A 97
#define F 102
#define LOWER_X 'x'
#define NULL_BYTE '\0'
#define NEWLINE '\n'
#define SIXTEEN 16
#define CHAR_TRANSFORM 87
#define DIGIT_TRANSFORM 48
#define MESSAGE "Integer value: %ld\n"
#define STRING_FORMAT "%s\n"
#define ERROR_MESSAGE "Error! Invalid input."

long htoi(char h[], double d); // declare htoi function
int validate(char c, int index); // declare validation function

int main() { // entry point
    int c; // holds input
    char input[HEX_BUFFER]; // limit for input
    int index = ZERO; // counter for exponents
    
    while ((c = getchar()) != EOF) { // get input
        if(c == NEWLINE) { break; } // display value on newline
        if(validate(c, index) == ZERO) { // check for valid characters
            printf(STRING_FORMAT, ERROR_MESSAGE); // display error on invalid input
            return TWO; // return error code
        }
        input[index] = c; // fill array
        ++index; // increment counter for exponents
    }
    
    for(int i = index; i < HEX_BUFFER; i++) { input[i] = NULL_BYTE; } // terminate excess input
    printf(MESSAGE, htoi(input, index)); // call htoi function and print result  
}

long htoi(char h[], double d) { // parse hex sting to return integer value
    long sum = ZERO; // initialize
    int x = d-ONE; // set exponent
    for(int i = ZERO; i < d; ++i) { // loop thorough string input
        if(i == ZERO && h[i] == LITERAL_ZERO) { x -= ONE; ++i; } // skip zero
        if(i == ONE && tolower(h[i]) == LOWER_X) { x -= ONE; ++i; }; // skip x
        if(!isdigit(h[i])) { // if not 0-9 transform to base 10
            sum += ((tolower(h[i]) - CHAR_TRANSFORM) * pow(SIXTEEN, x));
            --x;
        }
        if(isdigit(h[i])) { // for 0-9 character literal transform
            sum += ((h[i] - DIGIT_TRANSFORM) * pow(SIXTEEN, x));
            --x;
        }
    }
    return sum; // return integer value
}

// validator for invalid characters
int validate(char c, int index) {
    _Bool outRange = tolower(c) < A || tolower(c) > F; 
    if(index > HEX_BUFFER) { return ZERO; } // buffer overflow handling
    if(index != ONE && tolower(c) == LOWER_X) { return ZERO; } // x can only be second element
    if(!isdigit(c) && outRange && tolower(c) != LOWER_X) { return ZERO; } // A-F and 0-9 only
    else { return ONE; } // successful validation
}
