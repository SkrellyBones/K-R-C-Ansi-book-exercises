
#include <limits.h>
#include <stdio.h>
long power(long base, long exp) {
    long result = 1;
    for (long i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main(void) {
    printf("signed char:   %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char: 0 to %u\n", UCHAR_MAX);

    printf("signed short:  %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: 0 to %u\n", USHRT_MAX);

    printf("signed int:    %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int:  0 to %u\n", UINT_MAX);

    printf("signed long:   %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: 0 to %lu\n", ULONG_MAX);
    printf("-----------------------------------\n");
    char cmax = 0;
    while (1) {
        char next = cmax + 1;
        if (next < cmax) break; // overflow point
        cmax = next;
    }
    char cmin = -cmax - 1;

    unsigned char ucmax = 0;
    while (1) {
        unsigned char next = ucmax + 1;
        if (next < ucmax) break;
        ucmax = next;
    }

    int imax = 0;
    while (1) {
        int next = imax + 1;
        if (next < imax) break;
        imax = next;
    }
    int imin = -imax - 1;

    unsigned int uimax = 0;
    while (1) {
        unsigned int next = uimax + 1;
        if (next < uimax) break;
        uimax = next;
    }

    printf("Calculated:\n");
    printf("Char: %d to %d\n", cmin, cmax);
    printf("Unsigned Char: 0 to %u\n", ucmax);
    printf("Int: %d to %d\n", imin, imax);
    printf("Unsigned Int: 0 to %u\n", uimax);

    return 0;
}
