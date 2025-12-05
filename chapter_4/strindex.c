/*function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none.*/
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
int strindex(char s[], char t[]);
char line[MAXLINE];
char pattern[] = "ould";
int main() {
    int found = 0;
    while (fgets(line, MAXLINE, stdin) != NULL)
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    return found;
}
int strindex(char s[], char t[]) {
    int i, j, k;
    int rightmost = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            rightmost = i;
    }
    return rightmost;
}
