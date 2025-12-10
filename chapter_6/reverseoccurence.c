//Write a program that prints the distinct words in its input sorted into decreasing
//order of frequency of occurrence. Precede each word by its count.
#define NKEYS (sizeof keytab / sizeof(keytab[0]))
struct key {
    char *word;
    int count;
} keytab[NKEYS];
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAXWORD 100
int getword(char *, int);
int binsearch(char *, struct key *, int);
int main(){
    int n;
    char word[MAXWORD];
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    // Sort keytab by count in decreasing order
    for (int i = 0; i < NKEYS - 1; i++) {
        for (int j = i + 1; j < NKEYS; j++) {
            if (keytab[i].count < keytab[j].count) {
                struct key temp = keytab[i];
                keytab[i] = keytab[j];
                keytab[j] = temp;
            }
        }
    }
    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
    return 0;
}
int binsearch(char *word, struct key tab[], int n) {
    int cond;
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
return -1;
}
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

