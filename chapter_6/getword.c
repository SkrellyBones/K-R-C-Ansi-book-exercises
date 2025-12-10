#include <ctype.h>
#include <stdio.h>
/* getword: get next word or character from input */
int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}
//version that handles underscores, string constants, comments, and preprocessor control lines
int getword_enhanced(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (c == '#') { 
        while ((c = getch()) != '\n' && c != EOF)
            ;
        *w = '\0';
        return '#';
    }
    if (c == '/') {
        if ((c = getch()) == '*') { 
            while (1) {
                c = getch();
                if (c == EOF)
                    break;
                if (c == '*') {
                    if ((c = getch()) == '/')
                        break;
                    else
                        ungetch(c);
                }
            }
            *w = '\0';
            return '/';
        } else {
            ungetch(c);
            *w = '\0';
            return '/';
        }
    }
    if (c == '\"') { 
        *w++ = c;
        while ((c = getch()) != '\"' && c != EOF) {
            *w++ = c;
        }
        *w++ = c; 
        *w = '\0';
        return '\"';
    }
    if (!isalpha(c) && c != '_') {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch()) && *w != '_') {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}
