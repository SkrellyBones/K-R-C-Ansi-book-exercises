#include <stdio.h>
// program that replaces tabs with the correct number of spaces to the next tab
// stop
#define N 4 // tab stop every 4 columns
int main() {
    int c;
    int i;
    int col;
    col = 0;
    while ((c = getchar()) != EOF) {

        if (c == '\t') {
            int spaces = N - (col % N);
            for (i = 0; i < spaces; ++i) {
                putchar(' ');
                col += spaces;
            }
        } else {
            putchar(c);
            ++col;
            if (c == '\n')
                col = 0;
        }
    }
}
