void itob(int n, char s[], int b){
    int i = 0;
    int sign;
    if ((sign = n) < 0)
        n = -n;
    do {
        s[i++] = (n % b < 10) ? n % b + '0' : n % b - 10 + 'A';
    } while ((n /= b) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        char temp = s[j];
        s[j] = s[i - j - 1];
        s[i - j - 1] = temp;
    }
}
