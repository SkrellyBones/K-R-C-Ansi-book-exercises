#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000   
#define MAXLINES 5000 
#define DEFAULT_N 10

int getLine(char *s, int lim);
char *alloc(int);
char *allocbuf[MAXLINES]; 


static char alloc_storage[50000];
static char *allocp = alloc_storage;

char *alloc(int n) {
    if (alloc_storage + sizeof(alloc_storage) - allocp >= n) {
        allocp += n;
        return allocp - n;
    }
    return NULL; 
}

int main(int argc, char *argv[]) {
    int n = DEFAULT_N;

    if (argc > 1 && (*argv[1] == '-')) {
        n = atoi(argv[1] + 1);
        if (n < 1)
            n = DEFAULT_N;
    }

    if (n > MAXLINES)
        n = MAXLINES;

    char line[MAXLEN];
    char *ring[MAXLINES];
    int count = 0;
    int start = 0;

    while (getLine(line, MAXLEN) > 0) {
        char *p = alloc(strlen(line) + 1);
        if (p == NULL) {
            fprintf(stderr, "tail: out of memory\n");
            exit(1);
        }
        strcpy(p, line);

        ring[count % n] = p;
        count++;
    }

    //nothing read 
    if (count == 0)
        return 0;

    if (count > n)
        start = count % n;
    else
        start = 0;

    int printed = (count < n ? count : n);

    for (int i = 0; i < printed; i++) {
        int idx = (start + i) % n;
        printf("%s", ring[idx]);
    }

    return 0;
}

int getLine(char *s, int lim) {
    int c;
    char *p = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *p++ = c;

    if (c == '\n')
        *p++ = c;

    *p = '\0';
    return p - s;
}
