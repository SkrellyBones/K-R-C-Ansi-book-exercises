
#include <stdio.h>

int itoa(int n, char s[]) {
    int i = 0;
    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }
    if (n / 10)
        i += itoa(n / 10, s + i);
    s[i++] = n % 10 + '0';
    s[i] = '\0';
    return i;
}
int main() {
    char s[20];
    int hello[11] = {72, 101, 108, 108, 111, 32, 87, 111, 114, 108, 100};
    int lenh = sizeof(hello) / sizeof(hello[0]);

    for (int i = 0; i < lenh; i++)
        printf("%d ", hello[i]);
    printf("\n");
    for (int i = 0; i < lenh; i++) {
        itoa(hello[i], s);
        for (int j = 0; s[j] != '\0'; j++)
            printf("%c ", s[j]);
        printf("  ");
    }
    printf("\n");
    return 0;
}
