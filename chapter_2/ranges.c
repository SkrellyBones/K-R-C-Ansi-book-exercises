
#include <stdio.h>
#include <limits.h>

int power(int base, int n);

int main(void) {

    printf("Char: %d - %d\n", CHAR_MIN, CHAR_MAX);
    printf("Unsigned Char: %u - %u\n", 0U, UCHAR_MAX);

    printf("Short: %d - %d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned Short: %u - %u\n", 0U, USHRT_MAX);

    printf("Int: %d - %d\n", INT_MIN, INT_MAX);
    printf("Unsigned Int: %u - %u\n", 0U, UINT_MAX);

    printf("Long: %ld - %ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned Long: %u - %lu\n", 0U, ULONG_MAX);

    printf("------------------------------------\n");

    int bits_char  = sizeof(char)  * CHAR_BIT;
    int bits_short = sizeof(short) * CHAR_BIT;
    int bits_int   = sizeof(int)   * CHAR_BIT;
    int bits_long  = sizeof(long)  * CHAR_BIT;


    #define SIGNED_MAX(bits)   ( power(2, (bits)-1) - 1 )

    #define SIGNED_MIN(bits)   ( -power(2, (bits)-1) )

    #define UNSIGNED_MAX(bits) ( (unsigned long long)power(2, bits) - 1 )

    signed char sc_min = (signed char) SIGNED_MIN(bits_char);
    signed char sc_max = (signed char) SIGNED_MAX(bits_char);
    unsigned char uc_max = (unsigned char) UNSIGNED_MAX(bits_char);

    printf("Char: %d - %d\n", sc_min, sc_max);
    printf("Unsigned Char: %u - %u\n", 0U, uc_max);

    short ss_min = (short) SIGNED_MIN(bits_short);
    short ss_max = (short) SIGNED_MAX(bits_short);
    unsigned short us_max = (unsigned short) UNSIGNED_MAX(bits_short);

    printf("Short: %d - %d\n", ss_min, ss_max);
    printf("Unsigned Short: %u - %u\n", 0U, us_max);

    int si_min = SIGNED_MIN(bits_int);
    int si_max = SIGNED_MAX(bits_int);
    unsigned int ui_max = (unsigned int) UNSIGNED_MAX(bits_int);

    printf("Int: %d - %d\n", si_min, si_max);
    printf("Unsigned Int: %u - %u\n", 0U, ui_max);

    long sl_min = (long) SIGNED_MIN(bits_long);
    long sl_max = (long) SIGNED_MAX(bits_long);
    unsigned long ul_max = (unsigned long) UNSIGNED_MAX(bits_long);

    printf("Long: %ld - %ld\n", sl_min, sl_max);
    printf("Unsigned Long: %u - %lu\n", 0U, ul_max);

    return 0;
}

int power(int base, int n) {
    int p = 1;
    for (int i = 1; i <= n; ++i)
        p = p * base;
    return p;
}
