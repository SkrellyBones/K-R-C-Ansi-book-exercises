#include <ctype.h>
#include <stdio.h>
int getch(void);
void ungetch(int);
/*getfloat: get next float from input into *pn*/
int getfloat(float *pn) {
    int c, d;
    int sign;
    float power = 1.0;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        d = getch();
        if (!isdigit(d) && d != '.') {
            ungetch(d);
            ungetch(c);
            return 0;
        }
        c = d;
    }
    *pn = 0;
    while (isdigit(c)) {
        *pn = 10 * *pn + (c - '0');
        c = getch();
    }
    if (c == '.') {
        c = getch();
        while (isdigit(c)) {
            *pn = 10 * *pn + (c - '0');
            power *= 10;
            c = getch();
        }
    }
    *pn = sign * (*pn / power);
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
