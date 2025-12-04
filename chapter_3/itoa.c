/* itoa: convert n to characters in s */
#include <string.h>
#include <stdio.h>
int reverse(char s[]);
void itoa(int n, char s[]) {
    int i, sign;
    if ((sign = n) < 0) /* record sign */
        n = -n;
    /* make n positive */
    i = 0;
    do {
        /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0);
    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
int reverse(char s[]) {
    int i, j;
    char c;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return 0;
}
int main() {
    char s[20];
    itoa(-12345, s);
    return 0;
}
