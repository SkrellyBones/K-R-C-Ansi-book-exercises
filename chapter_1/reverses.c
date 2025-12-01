#include <stdio.h>
#define MAXLINE 1000
int getLine(char line[], int maxline);
void reverses(char to[], char from[], int len);
// print the longest line
int main() {

  int len;
  char line[MAXLINE];
  char reverse[MAXLINE];

  while ((len = getLine(line, MAXLINE)) > 0) {

    reverses(reverse, line, len);
    printf("%s", reverse);
  }

  return 0;
}

// getline: read a line into s, return length
int getLine(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  return i;
}

// reverses copy "from" into "to" backwards
void reverses(char to[], char from[], int len) {
  int i;
  int j;
  int newline;
  j = 0;
  if (from[len - 1] == '\n') {
    len--; // exclude newline from reversal
    newline = 1;
  } else {
    newline = 0;
  }
  for (i = len - 1; i >= 0; --i) {
    to[j] = from[i];
    ++j;
  }
  if (newline == 1) {
    to[len] = '\n';
    to[len + 1] = '\0';
  } else {

    to[j] = '\0';
  }
}
