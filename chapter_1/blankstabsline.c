#include <stdio.h>
#define MAXLINE 1000
int getLine(char line[], int maxline);
void copy(char to[], char from[]);
// print the longest line
int main() {

  int len;
  char line[MAXLINE];
  char newline[MAXLINE];
  int i;
  int j;
  while ((len = getLine(line, MAXLINE)) > 0) {
    j =0;
    for (i = 0; i <len; ++i)
      if (line[i] != '\t' && line[i] != ' ') {
        newline[j] = line[i];
        j++;
      }
        
    newline[j] = '\0';
    if (newline[0] != '\0'&&newline[0]!='\n')
      printf("%s\n", newline);


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
  s[i] = '\0';
  return i;
}

// copy copy "from" into "to"
void copy(char to[], char from[]) {
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
