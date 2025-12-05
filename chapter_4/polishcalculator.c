#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXOP 100
#define NUMBER '0'
int getop(char[]);
void push(double);
double pop(void);
double vars[26];
double last = 0.0;
/* reverse Polish calculator */
int sp = 0;
int main() {
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            last = pop();
            printf("\t%.8g\n", pop());
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push((double)((int)pop() % (int)op2));
            else
                printf("error: zero divisor for modulus\n");
            break;
        case 's': /* sine from math.h */
            push(sin(pop()));
            break;
        case 'e': /* exponential */
            push(exp(pop()));
            break;
        case 'p': /* power */
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case 't': /* print top element without popping */
            op2 = pop();
            printf("\tTop element: %.8g\n", op2);
            push(op2);
            break;
        case 'd': /* duplicate top element */
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 'w': /* swap top two elements */
        {
            double op1 = pop();
            double op2 = pop();
            push(op1);
            push(op2);
        } break;
        case 'c': /* clear stack */
            sp = 0;
            break;
        case 'v': { /*handle varialbes */
            double value;
            value = pop();   /* value to store */
            int var = pop(); /* variable letter */

            if (var >= 'a' && var <= 'z') {
                vars[var - 'a'] = value;
                push(value);
            } else {
                printf("error: invalid variable name\n");
            }
            break;
        }
        case 'r': {
            push(last);
            break;
        }
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}
#define MAXVAL 100

double val[MAXVAL];
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}
/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
#include <ctype.h>
int getch(void);
void ungetch(int);
/* getop: get next character or numeric operand */
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
#define BUFSIZE 100
int buf;
int bufp = 0;
/* buffer for ungetch */
/* next free position in buf */
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
    if (c== EOF)
        return;
    else {
        buf = c;
        bufp = 1;
    }
}
void ungets(char s[]) {
    // push back entire string into input
    int len = 0;
    while (s[len] != '\0')
        len++;
    while (len > 0)
        ungetch(s[--len]);
}
