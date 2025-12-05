
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXOP 100
#define NUMBER '0'
int getop(char[]);
void push(double);
double pop(void);
int getLine(char s[],int m);
double vars[26];
double last = 0.0;
char line[1000];
int li = 0;
int len = 0;
/* reverse Polish calculator using getline instead of getch and ungetch */
int sp = 0;
int main() {
    int type;
    double op2;
    char s[MAXOP];
    while ((len = getLine(line, 1000)) > 0) {
        li = 0;
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


int getLine(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int getch(void) {
    if (li < len)
        return line[li++];
    return EOF;
}

void ungetch(int c) {
    if (li > 0)
        li--;
}
