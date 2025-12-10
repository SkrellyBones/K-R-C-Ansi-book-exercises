//a cross-referencer that prints a list of all words in a document, and for
//each word, a list of the line numbers on which it occurs. Remove noise words like ``the,''
//``and,'' and so on.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXWORD 100
#define MAXLINE 1000
#define MAXNOISE 100
#define MAXLINES 1000
#define HASH_SIZE 101
struct LineNode {
    int lineNumber;
    struct LineNode *next;
};
struct WordNode {
    char *word;
    struct LineNode *lines;
    struct WordNode *next;
};
struct WordNode *hashTable[HASH_SIZE];
char *noiseWords[MAXNOISE];
int noiseWordCount = 0;
unsigned hash(char *s) {
    unsigned hashval = 0;
    for (; *s; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASH_SIZE;
}
int isNoiseWord(char *word) {
    for (int i = 0; i < noiseWordCount; i++) {
        if (strcmp(word, noiseWords[i]) == 0)
            return 1;
    }
    return 0;
}
struct WordNode *lookup(char *word) {
    unsigned hashval = hash(word);
    struct WordNode *wp;
    for (wp = hashTable[hashval]; wp != NULL; wp = wp->next) {
        if (strcmp(word, wp->word) == 0)
            return wp;
    }
    return NULL;
}
struct WordNode *insertWord(char *word, int lineNumber) {
    struct WordNode *wp = lookup(word);
    if (wp == NULL) {
        wp = (struct WordNode *)malloc(sizeof(struct WordNode));
        wp->word = strdup(word);
        wp->lines = NULL;
        unsigned hashval = hash(word);
        wp->next = hashTable[hashval];
        hashTable[hashval] = wp;
    }
    struct LineNode *lp = wp->lines;
    while (lp != NULL) {
        if (lp->lineNumber == lineNumber)
            return wp;
        lp = lp->next;
    }
    lp = (struct LineNode *)malloc(sizeof(struct LineNode));
    lp->lineNumber = lineNumber;
    lp->next = wp->lines;
    wp->lines = lp;
    return wp;
}
void printCrossReference() {
    for (int i = 0; i < HASH_SIZE; i++) {
        struct WordNode *wp;
        for (wp = hashTable[i]; wp != NULL; wp = wp->next) {
            printf("%s:", wp->word);
            struct LineNode *lp;
            for (lp = wp->lines; lp != NULL; lp = lp->next) {
                printf(" %d", lp->lineNumber);
            }
            printf("\n");
        }
    }
}
}
void loadNoiseWords(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open noise words file");
        exit(EXIT_FAILURE);
    }
    char word[MAXWORD];
    while (fscanf(file, "%s", word) != EOF) {
        noiseWords[noiseWordCount++] = strdup(word);
    }
    fclose(file);
}
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <inputfile> [noisewordsfile]\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (argc == 3) {
        loadNoiseWords(argv[2]);
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Could not open input file");
        return EXIT_FAILURE;
    }
    char word[MAXWORD];
    int lineNumber = 1;
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            lineNumber++;
        }
        if (isalpha(c)) {
            int i = 0;
            do {
                word[i++] = tolower(c);
                c = fgetc(file);
            } while (isalpha(c) && i < MAXWORD - 1);
            word[i] = '\0';
            if (!isNoiseWord(word)) {
                insertWord(word, lineNumber);
            }
            if (c == EOF) {
                break;
            }
        }
    }
    fclose(file);
    printCrossReference();
    return EXIT_SUCCESS;
}

