//itoa that takes a third argument specifying the minimum width of the output string.
void itoa3(int n, char s[], int min_width) {
    int i = 0;
    int is_negative = 0;

    if (n < 0) {
        is_negative = 1;
        n = -n;
    }

    do {
        s[i++] = (n % 10) + '0';
        n /= 10;
    } while (n > 0);

    if (is_negative) {
        s[i++] = '-';
    }
    //add padding spaces
    while (i < min_width) {
        s[i++] = ' ';
    }

    s[i] = '\0';

    for (int j = 0; j < i / 2; j++) {
        char temp = s[j];
        s[j] = s[i - j - 1];
        s[i - j - 1] = temp;
    }
}
