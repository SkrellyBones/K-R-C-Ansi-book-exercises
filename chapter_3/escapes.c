/*function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write
a function for the other direction as well, converting escape sequences into the real characters.*/
#include <stdio.h>
void escape(char s[], char t[]) {
    int i, j;
    i = j = 0;
    while (t[i] != '\0') {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
        i++;
    }
    s[j] = '\0';
}
void unescape(char s[], char t[]) {
    int i, j;
    i = j = 0;
    while (t[i] != '\0') {
        if (t[i] == '\\') {
            i++;
            switch (t[i]) {
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                default:
                    s[j++] = '\\';
                    s[j++] = t[i];
                    break;
            }
        } else {
            s[j++] = t[i];
        }
        i++;
    }
    s[j] = '\0';
}
int main() {
    char s[100], t[] = "Hello,\nWorld!\t";
    escape(s, t);
    printf("Escaped: %s\n", s);
    char u[100];
    unescape(u, s);
    printf("Unescaped: %s\n", u);
    return 0;
}
