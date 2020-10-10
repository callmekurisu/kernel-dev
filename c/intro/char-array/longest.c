#include <stdio.h>
#define MAXLINE 1000
#define LONG_LINE 20
#define BLANK ' '
#define TAB '\t'
/* maximum input line length */
int getLine(char line[], int maxline);
void copy(char to[], char from[]);
/* print the longest input */
main() {
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > LONG_LINE) { /* there was a line */
        printf("Longest length: %d\n", max);
        printf("%s\n", longest);
    }
    return 0;
}
/* getline: read a line into s, return length */
int getLine(char s[], int lim) {
    int c, i;

//      for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
//          s[i] = c; 
//      }
        
    // re-write for loop without && or ||
    i = 0;
    while((c=getchar()) != EOF) {
        if(i > lim -1) { break; }
        if(c == EOF) { break; }
        if(c == '\n') { break; }
        s[i] = c;
        ++i;
    }
    
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') {
        // trim excess whitespace
        if(to[i] == BLANK && from[i+1] == BLANK) { from[i+2] = '\b'; }
        ++i;
    }
}
