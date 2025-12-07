#include <ctype.h>
#include <stdio.h>
int getch(void);
void ungetch(int);
/* getint: get next integer from input into *pn */
int getint(int *pn) {
    int c, sign;
    while (isspace(c = getch()))
        /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-'){
        sign = (c == '-')? -1:1;

        int d = getch();
        if(!isdigit(d)){
            ungetch(d);
            ungetch(c);
            return 0;
        }
        c=d;
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

#define BUFSIZE 100
int buf;
int bufp = 0;
int getch(void) /* get a (possibly pushed-back) character, modified to assume
                   there will never be more than one */
{
    if (bufp == 1) {
        bufp = 0;
        return buf;
    }
    return getchar();
}
void ungetch(int c)
/* push character back on input, modified to assume there will never be more
   than one pushed back character */
{
    if (bufp == 1)
        printf("ungetch: too many characters\n");
    if (c == EOF)
        return;
    else {
        buf = c;
        bufp = 1;
    }
}

