#include <stdio.h>
#include<stdlib.h>
#include "calc.h"
#include <math.h>
#define MAXOP 100
double vars[26];
double last = 0.0;
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
