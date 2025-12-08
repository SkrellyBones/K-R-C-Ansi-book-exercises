/*getop: get next character or numeric operand*/
#include <ctype.h>
#include <stdio.h>
int getch(void);
void ungetch(int);
#define NUMBER '0'
int getop(char *s) {
    char *p = s;
    int c;
    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '-') {
        int next = c;
        if (isdigit(c = getch()) || c == '.') {
            *p++ = c;
            c = next;
        } else {
            ungetch(c);
            return '-';
        }
    }
    if (!isdigit(c) && c != '.') {
        *p = '\0';
        return c;
    }
    while (isdigit(*p++ = c))
           c = getch();
        ;
    if (*(p-1)== '.')
        while (isdigit(*p++ = c = getch()))
            ;
    *p = '\0';        
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
//so far pointers kind of make me sad ;-;
