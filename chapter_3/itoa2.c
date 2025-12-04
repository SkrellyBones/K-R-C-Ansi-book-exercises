/*In a two's complement number representation, our version of itoa does not
handle the largest negative number, that is, the value of n equal to
-(2wordsize-1). Explain why not. Modify it to print that value correctly,
regardless of the machine on which it runs*/
// it does not handle the largest negative number because in two's complement
// representation, the absolute value of the largest negative number cannot be
// represented as a positive number within the same bit-width. For example, in a
// 32-bit system, the largest negative number is -2147483648, but its positive
// counterpart, 2147483648, exceeds the maximum positive value of 2147483647
// that can be represented in 32 bits.
#include <limits.h>
#include <stdio.h>
void itoa(int n, char s[]) {
    int i = 0;
    int is_negative = 0;

    if (n == INT_MIN) {
        s[i++] = '-';
        s[i++] = '2';
        n = 147483648;
    } else {
        if (n < 0) {
            is_negative = 1;
            n = -n;
        }
    }

    do {
        s[i++] = (n % 10) + '0';
        n /= 10;
    } while (n > 0);

    if (is_negative) {
        s[i++] = '-';
    }

    s[i] = '\0';

    for (int j = 0; j < i / 2; j++) {
        char temp = s[j];
        s[j] = s[i - j - 1];
        s[i - j - 1] = temp;
    }
}
