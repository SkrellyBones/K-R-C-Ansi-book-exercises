#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXTABS 100
#define DEFAULT_TAB 8
int settabs(int argc, char*argv[], int *tabs);
int nexttab(int col, int *tabs, int ntabs);
void entab(int *tabs, int ntabs);
void detab(int *tabs, int ntabs);
int main(int argc, char *argv[]){
    int tabs[MAXTABS];
    int ntabs = settabs(argc, argv, tabs);
    detab(tabs,ntabs);
    entab(tabs,ntabs);
    return 0;
    
}
int settabs(int argc, char *argv[], int *tabs) {
    int n = 0;
    if (argc <= 1) {
        int pos = DEFAULT_TAB;
        while (pos < 1000 && n < MAXTABS) {
            tabs[n++] = pos;
            pos += DEFAULT_TAB;
        }
        return n;
    }
    argv++;  
    argc--;
    while (argc-- > 0 && n < MAXTABS) {
        tabs[n++] = atoi(*argv++);
    }
    return n;
}
int nexttab(int col, int *tabs, int ntabs) {
    int *p = tabs;
    int *end = tabs + ntabs;

    while (p < end) {
        if (*p > col)
            return *p;
        p++;
    }
    return col + (DEFAULT_TAB - (col % DEFAULT_TAB));
}
void entab(int *tabs, int ntabs) {
    int c;
    int col = 0;
    int space_count = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            space_count++;
            int stop = nexttab(col, tabs, ntabs);
            if (col + space_count == stop) {
                putchar('\t');
                col = stop;
                space_count = 0;
            }
        } else {
            while (space_count > 0) {
                putchar(' ');
                col++;
                space_count--;
            }
            putchar(c);
            col++;
            if (c == '\n')
                col = 0;
        }
    }
}
void detab(int *tabs, int ntabs) {
    int c;
    int col = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int stop = nexttab(col, tabs, ntabs);
            while (col < stop) {
                putchar(' ');
                col++;
            }
        } else {
            putchar(c);
            col++;
            if (c == '\n')
                col = 0;
        }
    }
}
