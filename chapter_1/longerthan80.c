#include <stdio.h>
#define MAXLINE 1000
int getLine(char line[], int maxline);
void copy(char to[], char from[]);
// print the longest line
int main() {

  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];
  int total;
  int extra;
  int c;
  extra = 0;
  total = 0;
  max = 0;
  while ((len = getLine(line, MAXLINE)) > 0){
    if(line[len-1]!='\n'){
        while ((c=getchar())!= '\n'&& c!=EOF){
                extra =0;
                ++extra;}
        }
        total = len + extra;   
    if (len > max||total>max) {
      max = total;
      copy(longest, line);
    }
     if (total > 80){ // there was a line
    printf("%s", line);
     printf("characters :%d\n",total);}   
    }
 if (max >0){
    printf("Maximum line: \n%s\n",longest);
    printf("characters: %d\n",max);}
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
