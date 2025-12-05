#include <stdio.h>
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
