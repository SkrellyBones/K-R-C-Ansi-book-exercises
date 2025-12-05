#include <stdio.h>
#include <ctype.h>
#include "calc.h"
int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (c == '-') {
        if (isdigit(c = getch()) || c == '.')
            s[++i] = c; /* negative number */
        else {
            ungetch(c);
            return '-'; /* minus sign */
        }
    }
    if (!isdigit(c) && c != '.') {
        if (isalpha(c))
            return c;
        return c;
    }
    /* not a number */
    i = 0;
    if (isdigit(c))
        /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
