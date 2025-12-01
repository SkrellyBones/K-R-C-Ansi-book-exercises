#include <stdio.h>
#define MAXLINE 1000
#define N 80
int getLine(char line[], int maxline);
// program to ``fold'' long input lines into two or more shorter lines after
// the last non-blank character that occurs before the n-th column of input.
int main() {
  int len;
  char line[MAXLINE];

  while ((len = getLine(line, MAXLINE)) > 0) {
    int col = 0; // current column
    int last_blank = -1;

    for (int i = 0; i < len; ++i) {
      char c = line[i];

      if (c == ' ' || c == '\t')
        last_blank = col;

      putchar(c);
      col++;

      if (col >= N) {
        if (last_blank >= 0) {
          putchar('\n');
          col = col - last_blank - 1;
          last_blank = -1;
        } else {
          putchar('\n');
          col = 0;
        }
      }

      if (c == '\n')
        col = 0;
    }
  }

  return 0;
}

int getLine(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
