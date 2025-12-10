/*a simple version of the #define processor (i.e., no arguments)
suitable for use with C programs, based on the routines of this section. You may also find
getch and ungetch helpful.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLINE 1000
#define MAXDEFS 100
#define MAXTOKEN 100
struct Def {
    char name[MAXTOKEN];
    char value[MAXTOKEN];
} defs[MAXDEFS];
int defCount = 0;
char line[MAXLINE];
int getLine(char *s, int lim);
int getToken(char *token);
void addDef(const char *name, const char *value);
const char* lookupDef(const char *name);
int main() {
    while (getLine(line, MAXLINE) > 0) {
        char token[MAXTOKEN];
        int i = 0;
        while (line[i] != '\0') {
            if (isspace(line[i])) {
                putchar(line[i++]);
                continue;
            }
            int j = 0;
            while (line[i] != '\0' && !isspace(line[i])) {
                token[j++] = line[i++];
            }
            token[j] = '\0';
            if (strcmp(token, "#define") == 0) {
                char name[MAXTOKEN], value[MAXTOKEN];
                i += getToken(name);
                i += getToken(value);
                addDef(name, value);
            } else {
                const char *defValue = lookupDef(token);
                if (defValue) {
                    printf("%s", defValue);
                } else {
                    printf("%s", token);
                }
            }
        }
        putchar('\n');
    }
    return 0;
}
int getLine(char *s, int lim) {
    int c, i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}
int getToken(char *token) {
    int c, i = 0;
    while (isspace(c = line[i])) {
        i++;
    }
    if (c == '\0') {
        token[0] = '\0';
        return i;
    }
    while (c != '\0' && !isspace(c)) {
        token[i++] = c;
        c = line[i];
    }
    token[i] = '\0';
    return i;
}
void addDef(const char *name, const char *value) {
    if (defCount < MAXDEFS) {
        strcpy(defs[defCount].name, name);
        strcpy(defs[defCount].value, value);
        defCount++;
    }
}
const char* lookupDef(const char *name) {
    for (int i = 0; i < defCount; i++) {
        if (strcmp(defs[i].name, name) == 0) {
            return defs[i].value;
        }
    }
    return NULL;
}

