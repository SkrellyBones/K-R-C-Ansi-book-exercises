/*function strindex(s,t) which returns the position of the rightmost occurence
 * of t in s, or -1 if there is none*/
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
int strindex(char *s, char *t);
char line[MAXLINE];
char pattern[] = "ould";
int main() {
    int found = 0;
    while (fgets(line, MAXLINE, stdin) != NULL)
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    printf("found %d lines with an instance of 'ould'\n",found);
    return found;
}
int strindex(char *s, char *t) {
    int rightmost = -1;
    char *p = s;
    char *a = t;
    while (*p != '\0') {
        char *tempP = p;
        char *tempA =a;
        while (*tempA != '\0' && *tempP == *tempA) {
            tempA++;
            tempP++;
        }
        if (*tempA == '\0')
            rightmost = p-s;
        p++;
    }
    return rightmost;
}
