#include <stdio.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
        } else {
            putchar(' ');
            
            while ((c = getchar()) == ' ')
                ; 
            if (c == EOF) break;
            putchar(c);
        }
    }

    return 0;
}
