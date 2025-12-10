// a program that reads a C program and prints in alphabetical order each
// group of variable names that are identical in the first 6 characters, but
// different somewhere thereafter. Don't count words within strings and
// comments. Make 6 a parameter that can be set from the command line.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORD 100
#define MAXVARS 1000
#define DEFAULT_N 6
#define MAXLINE 1000
#define IN 1
#define OUT 0
struct varnode {
    char *name;
    struct varnode *next;
};
struct groupnode {
    char *prefix;
    struct varnode *vars;
    struct groupnode *next;
};
struct groupnode *groups = NULL;
int n = DEFAULT_N;
void add_variable(char *word);
void print_groups();
int getword(char *word, int lim);
int main(int argc, char *argv[]) {
    char word[MAXWORD];
    if (argc > 1) {
        n = atoi(argv[1]);
        if (n <= 0 || n >= MAXWORD) {
            fprintf(stderr, "Invalid value for n. Using default %d.\n",
                    DEFAULT_N);
            n = DEFAULT_N;
        }
    }
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) || word[0] == '_') {
            add_variable(word);
        }
    }
    print_groups();
    return 0;
}
void add_variable(char *word) {
    char prefix[MAXWORD];
    struct groupnode *g;
    struct varnode *v;
    strncpy(prefix, word, n);
    prefix[n] = '\0';
    for (g = groups; g != NULL; g = g->next) {
        if (strcmp(g->prefix, prefix) == 0) {
            for (v = g->vars; v != NULL; v = v->next) {
                if (strcmp(v->name, word) == 0) {
                    return; // variable already exists
                }
            }
            v = (struct varnode *)malloc(sizeof(struct varnode));
            v->name = strdup(word);
            v->next = g->vars;
            g->vars = v;
            return;
        }
    }
    g = (struct groupnode *)malloc(sizeof(struct groupnode));
    g->prefix = strdup(prefix);
    g->vars = NULL;
    v = (struct varnode *)malloc(sizeof(struct varnode));
    v->name = strdup(word);
    v->next = NULL;
    g->vars = v;
    g->next = groups;
    groups = g;
}
void print_groups() {
    struct groupnode *g;
    struct varnode *v;
    for (g = groups; g != NULL; g = g->next) {
        int count = 0;
        for (v = g->vars; v != NULL; v = v->next) {
            count++;
        }
        if (count > 1) {
            printf("Group with prefix '%s':\n", g->prefix);
            for (v = g->vars; v != NULL; v = v->next) {
                printf("  %s\n", v->name);
            }
        }
    }
}
int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    while (isspace(c = getch()))
        ;
    if (c == EOF) {
        return EOF;
    }
    if (isalpha(c) || c == '_') {
        *w++ = c;
        for (; --lim > 0; w++) {
            c = getch();
            if (!isalnum(c) && c != '_') {
                ungetch(c);
                break;
            }
            *w = c;
        }
        *w = '\0';
        return word[0];
    }
    if (c == '/') {
        if ((c = getch()) == '*') {
            while ((c = getch()) != EOF) {
                if (c == '*') {
                    if ((c = getch()) == '/') {
                        break;
                    } else {
                        ungetch(c);
                    }
                }
            }
            return getword(word, lim);
        } else {
            ungetch(c);
            return '/';
        }
        if (c == '"') {
            while ((c = getch()) != EOF && c != '"')
                ;
            return getword(word, lim);
        }
        *w++ = c;
        *w = '\0';
        return c;
    }
    return c;
}
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}
