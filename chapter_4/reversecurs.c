#include <stdio.h>
#include <string.h>
void reverses(char to[], char from[], int len, int i) {
    if (i < 0)
        return;
    int j = len - 1 - i;
    to[j] = from[i];
    reverses(to, from, len, i - 1);
}
int main() {
    char from[] = "Hello World!";
    int len = strlen(from);
    char to[len + 1];
    reverses(to, from, len, len - 1);
    to[len] = '\0';
    printf("Original: %s\n", from);
    printf("Reversed: %s\n", to);

    return 0;
}
