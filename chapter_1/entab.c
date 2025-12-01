
#include <stdio.h>

#define N 4 // tab stop every 4 columns

int main() {
  int c;
  int col = 0;    // current column
  int spaces = 0; // count of consecutive spaces

  while ((c = getchar()) != EOF) {

    if (c == ' ') {
      spaces++;
      col++;
    } else {
      // we hit a non-space → convert saved spaces
      int start_col = col - spaces;
      int s = spaces;
      int cur = start_col;

      // output as many tabs as possible
      while (s > 0) {
        int to_tab = N - (cur % N); // distance to next tab stop

        if (s >= to_tab) {
          putchar('\t');
          cur += to_tab;
          s -= to_tab;
        } else {
          break;
        }
      }

      // output remaining spaces
      while (s-- > 0) {
        putchar(' ');
        cur++;
      }

      spaces = 0;
      col = cur;

      // now output the non-space char
      putchar(c);
      if (c == '\n')
        col = 0;
      else
        col++;
    }
  }

  return 0;
}
